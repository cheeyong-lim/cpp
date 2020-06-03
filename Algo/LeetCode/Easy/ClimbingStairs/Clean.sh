[ -d Scripts/ ] && pushd Scripts/ && ./Clean.sh && popd
[ -d Scripts/ ] && rm -rf Scripts/
[ -d Utility/ ] && rm -rf Utility/
rm -f CMakeLists.txt
