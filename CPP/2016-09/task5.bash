
# bash task5.bash ab bc cd

count=1

for i in 6 1 4 2
do
    for each
    do
        if test $i -gt $#
        then
            count=` expr $count \* $i` # count=6 | count=36 | count=216
            echo $count $each >> f1 # 6 ab | 36 bc | 216 cd
        else
            until false
            do
            echo $* # ab bc cd
            break 3
            done
        fi
    done
done

# f1
# 6 ab
# 36 bc
# 216 cd

read k1 k2 # b c

while cat f1 | grep $k1 # 6 ab | 36 bc
do
    set $k1 $k2 $count # b c 216
    shift # c 216
    echo $1 $2 # c 216
    grep $2 f1 > f2 # 216 cd
    wc -c f2 # 7 f2
    exit
    echo END
done

wc -l f1 # 3 f1
tail -2l f1 # 36 bc | 216 cd
echo FIN