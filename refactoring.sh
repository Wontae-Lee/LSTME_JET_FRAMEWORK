find ./ -type f |xargs sed -i 's/\.h/\.hpp/g'
for f in *.h; do mv -- "$f" "${f%.h}.hpp"; done
find ./ -type f |xargs sed -i 's/jet/lstme/g'
find ./ -type f |xargs sed -i 's/JET/LSTME/g'
find ./ -type f |xargs sed -i 's/lstme\///g'