for D in $(find ./pictures/ -name '*.dot');
do 
    dot -Tpng -O $D;
done;
