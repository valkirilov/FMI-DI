#bash task5.bash ab cd ef gh

var=3 # var=3

for i # ab cd ef gh
do
    for j in `cat f1` # 1 3 5 2 4 6
    do
        if test $j -lt $#
        then
            echo $i $j # ab 1 | ab 3 | ab 2
            var=`expr $var \* $j` # 3 9 28 # 38 114 238 248 744 1498 1508 4524 9058
            # echo $var
            echo $var $i > f2 # last value
        else
            var=`expr $var + $j` # 14 32 38 # 119 242 248 749 1502 1508 4529 9062 9068
            # echo $var
            echo $var $j >> f2
        fi
    done
    break
done

# 28 ab
# 32 4
# 38 6

read s1 s2 # 8 3

until grep $s1 f2 # 28 ab | 38 6
do
    # not entering
    set $s2 $var $# # 8 38 4
    wc -c f2 # 16 f2
    shift # 38 4
    echo $1 $2 # 38 4
    exit
    cat f2 # f2 file
done

set `head -2l f2` # 28 ab 32 4
echo $* # 28 ab 32 4
shift # ab 32 4
echo $2 # 32