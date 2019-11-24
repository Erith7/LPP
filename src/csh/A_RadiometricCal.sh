#!/bin/csh

set INDIR_at=/media/erith/Disco4TB/Linux/FNF_Landsat_data/Datos2014/
set OUTDIR_RR=/media/erith/Disco4TB/Linux/Output/Mosaico2014LPP/
set LPP_path=/home/erith/Documentos/LPP
set Exec_path=$LPP_path'/'src/exe
set Source_path=$LPP_path'/'src/cppfiles
set Cshell_path=$LPP_path'/'src/csh

if (! -d $OUTDIR_RR) mkdir -p $OUTDIR_RR

cd $Source_path
rm -f *.exe
make -f rad.makefile
make -f georef.makefile
mv *.exe $Exec_path

cd $INDIR_at
set inplist_DAT = `ls -1`

foreach inpfile ( $inplist_DAT )  # Making the PathRow Files List
	echo $inpfile
	set pathrow = $inpfile'/'  # Defining the PathRow Directory
	cd $inpfile                # Getting in each PathRow File  
	set inlist_L = `ls -1`         #Listing the Landsat scenes inside the PathRow
	foreach inpimage ( $inlist_L )
		set Band_Name = $inpimage      # Taking the Image Name
		set ImageDir = $inpimage'/'	# Defining the Image Directory		
		echo $Band_Name	
		cd $inpimage                 #Getting in each image
		set intxt = `ls -1 *.txt`
			foreach texto ( $intxt )
			echo $intxt'     Copio .TXT'
			if (! -d $OUTDIR_RR$pathrow$ImageDir) mkdir -p $OUTDIR_RR$pathrow$ImageDir
			cp $texto $OUTDIR_RR$pathrow$ImageDir
			end
		cd ..
		$Exec_path'/LandSat_8_Radiance_Cal_16b.exe' $INDIR_at$pathrow$ImageDir $Band_Name $OUTDIR_RR$pathrow$ImageDir
		cp $INDIR_at$pathrow$ImageDir$Band_Name'_BQA.TIF' $OUTDIR_RR$pathrow$ImageDir$Band_Name'_BQA.TIF'
		# cd $OUTDIR_RR$pathrow$ImageDir		
	end
	cd ..
end 
exit
