curl -sSL "http://llvm.org/apt/llvm-snapshot.gpg.key" | sudo -E apt-key add -
sudo -E apt-get -yq --no-install-suggests --no-install-recommends --force-yes install cmake time swig
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF
echo "deb http://download.mono-project.com/repo/debian wheezy main" | sudo tee /etc/apt/sources.list.d/mono-xamarin.list
sudo apt-get update
sudo add-apt-repository ppa:ermshiperete/monodevelop
sudo apt-get update
mozroots --import --sync
sudo apt-get install -y cmake
sudo apt-get install -y swig
sudo apt-get install -y mono-complete 
sudo apt-get install -y monodevelop
sudo apt-get install -y nunit
sudo apt-get install -y nuget
sudo apt-get install -y git dpkg-dev make g++ gcc binutils libx11-dev libxpm-dev 
git clone --depth=50 --branch=master https://github.com/OlegJakushkin/TestSWIG.git
cd TestSWIG/
nuget restore TestSWIG.sln
nuget install NUnit.Runners -Version 2.6.4 -OutputDirectory testrunner
swig -c++ -csharp -namespace LibraryNamespace -I./CPP/Library/ -outdir CSharp/CSharpLibrary/ -o CSharp/CSharpWrapper/SimpleAPIWrapper.cxx CSharp/SimplifiedAPI.i
cmake -DCMAKE_BUILD_TYPE="Release" -G "Unix Makefiles" ./
make -j1
ls ./Build/Release/
xbuild /p:Configuration=Release ./CSharp/CSharpLibrary/CSharpLibrary.csproj
xbuild /p:Configuration=Release ./CSharp/Tests/Tests.csproj
ls ./Build/Release/
mono ./testrunner/NUnit.Runners.2.6.4/tools/nunit-console.exe ./Build/Release/CSharpTests.dll
