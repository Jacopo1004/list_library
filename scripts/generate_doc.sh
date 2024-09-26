#!/bin/bash
echo 'Setting up the script...'

# Get the current gh-pages branch
mkdir gh-pages
echo $(pwd)

# Load the list of things to be documented: data structure + elemtype
doxyfiles=$(cat scripts/conf_complete.txt)
echo '******'
echo $doxyfiles
echo '******'

################################################################################
##### Generate the Doxygen documentation (from master) and log the output. #####
echo 'Generating Doxygen code documentation...'

cwd=$(pwd)
for i in $doxyfiles; do
    echo "****************************************************"
	echo "* $i"
    echo "****************************************************"

	# Let's copy the required source and header files for generating the current doc
	echo "cp $i/../*.* $i"
	cp $i/../*.* $i
	type_name=$(basename $i)
	echo "cp elemtype/$type_name/*.* $i"
	cp elemtype/$type_name/*.* $i

	# Redirect both stderr and stdout to the log file and the console.
	cd $i/doxygen
	doxygen 2>&1 | tee doxygen.log
	echo $(ls -l)
	cd $cwd

	################################################################################
	##### Copy generated doc from master folder to gh-pages one.               #####
	dir=gh-pages/$i/html
	if [ -d "$dir" ]; then rm -Rf $dir; fi
	mkdir -p $dir
	mv $i/doxygen/html gh-pages/$i

	################################################################################
	##### Creation of the zip file for the download.                           #####
	cd $i
	headers=$(ls -I homepage.h | egrep '*.h$')
	sources=$(ls *.c)

	zip_name="${i//\//_}.zip"
	echo ${zip_name}
	zip ${zip_name} -r ${headers} ${sources}

	file=../../gh-pages/$i/${zip_name}
	if [ -f "$file" ]; then rm $file; fi
	mv ${zip_name} ${file}
	cd $cwd
done

# Load the list of things to be documented: only data structures
doxyfiles=$(cat scripts/conf_datastruct.txt)
echo '******'
echo $doxyfiles
echo '******'

cwd=$(pwd)
for i in $doxyfiles; do
    echo "****************************************************"
	echo "* $i"
    echo "****************************************************"

	# Redirect both stderr and stdout to the log file and the console.
	cd $i/doxygen
	doxygen 2>&1 | tee doxygen.log
	echo $(ls -l)
	cd $cwd

	################################################################################
	##### Copy generated doc from master folder to gh-pages one.               #####
	dir=gh-pages/$i/html
	if [ -d "$dir" ]; then rm -Rf $dir; fi
	mkdir -p $dir
	mv $i/doxygen/html gh-pages/$i

	################################################################################
	##### Creation of the zip file for the download.                           #####
	cd $i
	headers=$(ls $i.h)
	sources=$(ls $i.c)

	zip_name="${i}.zip"
	echo ${zip_name}
	zip ${zip_name} -r ${headers} ${sources}

	file=../gh-pages/$i/${zip_name}
	if [ -f "$file" ]; then rm $file; fi
	mv ${zip_name} ${file}

 	################################################################################
	##### Creation of main_list.zip file for the download.                           #####
	headers=$(ls main_list.h)
	sources=$(ls main_list.c)

	zip_name="main_list.zip"
	echo ${zip_name}
	zip ${zip_name} -r ${headers} ${sources}

	file=../gh-pages/$i/${zip_name}
	if [ -f "$file" ]; then rm $file; fi
	mv ${zip_name} ${file}
	cd $cwd

done

# Load the list of things to be documented: only elemtypes
doxyfiles=$(cat scripts/conf_elemtype.txt)
echo '******'
echo $doxyfiles
echo '******'

cwd=$(pwd)
for i in $doxyfiles; do
    echo "****************************************************"
	echo "* $i"
    echo "****************************************************"

	# Redirect both stderr and stdout to the log file and the console.
	cd elemtype/$i/doxygen
	doxygen 2>&1 | tee doxygen.log
	echo $(ls -l)
	cd $cwd

	################################################################################
	##### Copy generated doc from master folder to gh-pages one.               #####
	dir=gh-pages/elemtype/$i/html
	if [ -d "$dir" ]; then rm -Rf $dir; fi
	mkdir -p $dir
	mv elemtype/$i/doxygen/html gh-pages/elemtype/$i

	################################################################################
	##### Creation of the zip file for the download.                           #####
	cd elemtype/$i
	headers=$(ls *.h)
	sources=$(ls *.c)

	zip_name="elemtype_${i}.zip"
	echo ${zip_name}
	zip ${zip_name} -r ${headers} ${sources}

	file=../../gh-pages/elemtype/$i/${zip_name}
	if [ -f "$file" ]; then rm $file; fi
	mv ${zip_name} ${file}
	cd $cwd
done

echo $(ls -l gh-pages)

# Modifica del file HTML della documentazione di list per inserire il link al file zip
echo "Modifica del file HTML della documentazione di list per inserire il link al file zip..."

# File HTML generato da Doxygen per la documentazione di list
index_file="gh-pages/list/html/list_8h.html"

# Link al file zip da aggiungere
download_link="<p><a href=\"https://jacopo1004.github.io/list_library/list/list.zip\">Scarica il file zip della libreria list</a></p>"

# Verifica se il file esiste e aggiungi il link subito dopo il primo tag <body>
if [ -f "$index_file" ]; then
    # Usa sed per inserire il link subito dopo il primo tag <body>
    sed -i "s|<body>|<body>\n$download_link\n|" "$index_file"
    echo "Link aggiunto con successo a $index_file"
else
    echo "Il file $index_file non esiste!"
fi

# Modifica del file HTML della documentazione di list per inserire il link al file zip
echo "Modifica del file HTML della documentazione di main_list per inserire il link al file zip..."

# File HTML generato da Doxygen per la documentazione di list
index_file="gh-pages/list/html/main__list_8h.html"

# Link al file zip da aggiungere
download_link="<p><a href=\"https://jacopo1004.github.io/list_library/main_list/main__list.zip\">Scarica il file zip della libreria main_list</a></p>"

# Verifica se il file esiste e aggiungi il link subito dopo il primo tag <body>
if [ -f "$index_file" ]; then
    # Usa sed per inserire il link subito dopo il primo tag <body>
    sed -i "s|<body>|<body>\n$download_link\n|" "$index_file"
    echo "Link aggiunto con successo a $index_file"
else
    echo "Il file $index_file non esiste!"
fi
