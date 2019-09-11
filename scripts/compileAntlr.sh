compile() {
    echo "Compiling $2"

    pushd $1 > /dev/null

    if [ -d "generated" ]; then
        echo "Deleting old grammars"
        rm -r generated
    fi

    antlr4 -Dlanguage=Cpp -o generated -package Brill $2
    popd > /dev/null
    echo
}

echo "Compiling Antlr grammars"
echo
echo

compile src/lang Brill.g4
