#$MIRROR = 'http://http.us.debian.org/debian/pool/main/e/'
$MIRROR = 'http://ftp.jaist.ac.jp/pub/Linux/ubuntu//pool'

#http://ftp.jaist.ac.jp/pub/Linux/ubuntu//pool/main/l/linux/linux-libc-dev_3.8.0-19.29_amd64.deb
#http://ftp.jaist.ac.jp/pub/Linux/ubuntu//pool/universe/a/armel-cross-toolchain-base/linux-libc-dev-armel-cross_3.8.0-5.10cross1.101_all.deb
#http://ftp.jaist.ac.jp/pub/Linux/ubuntu//pool/main/e/eglibc/libc6_2.17-0ubuntu5_amd64.deb
#http://ftp.jaist.ac.jp/pub/Linux/ubuntu//pool/main/g/gcc-4.7/libgcc-4.7-dev_4.7.3-1ubuntu1_amd64.deb
#http://ftp.jaist.ac.jp/pub/Linux/ubuntu//pool/universe/g/gcc-4.7-armel-cross/libgcc-4.7-dev-armel-cross_4.7.3-1ubuntu1cross1.81_all.deb
#http://ftp.jaist.ac.jp/pub/Linux/ubuntu//pool/main/g/gcc-4.7/libgcc1_4.7.3-1ubuntu1_amd64.deb
#http://ftp.jaist.ac.jp/pub/Linux/ubuntu//pool/universe/g/gcc-4.7-armel-cross/libgcc1-armel-cross_4.7.3-1ubuntu1cross1.81_all.deb

$PACKAGES =
{
	'x86_64'=>
	[
        ['main/g/gcc-4.7','libgcc1_4.7.3-1ubuntu1_amd64.deb'],
        ['main/g/gcc-4.7','libgcc-4.7-dev_4.7.3-1ubuntu1_amd64.deb'],
        ['main/l/linux','linux-libc-dev_3.8.0-19.29_amd64.deb'],
        ['main/e/eglibc','libc6_2.17-0ubuntu5_amd64.deb'],
		['main/e/eglibc','libc6-dev_2.17-0ubuntu5_amd64.deb'],
	],
	'i386' =>
	[
        ['main/g/gcc-4.7','libgcc1_4.7.3-1ubuntu1_amd64.deb'],
        ['main/g/gcc-4.7','libgcc-4.7-dev_4.7.3-1ubuntu1_i386.deb'],
        ['main/l/linux','linux-libc-dev_3.8.0-19.29_i386.deb'],
		['main/e/eglibc','libc6_2.17-0ubuntu5_i386.deb'],
		['main/e/eglibc','libc6-dev_2.17-0ubuntu5_i386.deb'],
	],
    'armel' =>
    [
        ['universe/g/gcc-4.7-armel-cross','libgcc1-armel-cross_4.7.3-1ubuntu1cross1.81_all.deb'],
        ['universe/g/gcc-4.7-armel-cross','libgcc-4.7-dev-armel-cross_4.7.3-1ubuntu1cross1.81_all.deb'],
        ['universe/a/armel-cross-toolchain-base','linux-libc-dev-armel-cross_3.8.0-5.10cross1.101_all.deb'],
        ['universe/a/armel-cross-toolchain-base','libc6-armel-cross_2.17-0ubuntu2cross1.101_all.deb'],
        ['universe/a/armel-cross-toolchain-base','libc6-dev-armel-cross_2.17-0ubuntu2cross1.101_all.deb'],
    ],
    'armhf' =>
    [
        ['universe/g/gcc-4.7-armhf-cross','libgcc1-armhf-cross_4.7.3-1ubuntu1cross1.81_all.deb'],
        ['universe/g/gcc-4.7-armhf-cross','libgcc-4.7-dev-armhf-cross_4.7.3-1ubuntu1cross1.81_all.deb'],
        ['universe/a/armhf-cross-toolchain-base','linux-libc-dev-armhf-cross_3.8.0-5.10cross1.101_all.deb'],
        ['universe/a/armhf-cross-toolchain-base','libc6-armhf-cross_2.17-0ubuntu2cross1.101_all.deb'],
        ['universe/a/armhf-cross-toolchain-base','libc6-dev-armhf-cross_2.17-0ubuntu2cross1.101_all.deb'],
    ],
}
# download from web
$PACKAGES.each do |arch,packs|
	`mkdir -p sdk/#{arch}/`
	packs.each do |pack|
		filename = "sdk/#{arch}/#{pack[1]}"
		if not File.exists?(filename) then
			`wget #{$MIRROR}/#{pack[0]}/#{pack[1]} -O #{filename}`
		end
	end
end
`find sdk -type f -name *.deb`.split(/\n/).each do |deb|
	`dpkg-deb -x #{deb} #{File::dirname(deb)}/`
	`rm -f #{deb} `
end

$ARCHS=
{
	'x86_64' => 'x86_64-linux-gnu',
	'i386' => 'i386-linux-gnu',
	'armel' => 'arm-linux-gnueabi',
	'armhf' => 'arm-linux-gnueabihf',
}
$ARCHS.each do |name,arch|
	namedir= `find sdk -type d -name "#{name}"`.gsub(/\n/,"")
	`tar -cjvf #{arch}.tar.bz2 -C #{namedir} .`
end
