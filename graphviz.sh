for D in $(find . -name '*.dot'); 
do 
    dot -Tpng -O $D;
done;
