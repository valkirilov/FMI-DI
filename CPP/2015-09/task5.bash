var=1

for i in 4 3 2 1
do
    for j
    do
        # echo $i $j $#
        if test $i -gt $#
        then
            var=`expr $var \* $i`
            echo $var $j >> ff
            # echo $var $j
            # 4 12
            # 16 34
            # 64 56
        else
            continue
        fi

    done
done

while true
do
    echo $*
    break
done
# 12 34 56

read k1 k2
# 5 6

while cat ff | grep $k2
do
    # 16 34
    # 64 56

    set $k1 $var # 5 64
    echo $1 $2
    shift # 64
    echo $2 # emptty string
    grep $i ff
    # 4 12
    # 16 34
    exit
    echo $1
done

wc -l << ff
echo END