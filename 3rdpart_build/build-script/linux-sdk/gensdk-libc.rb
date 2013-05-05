RROR = 'http://http.us.debian.org/debian/pool/main/e/'
$MIRROR = 'http://ftp.jaist.ac.jp/pub/Linux/ubuntu//pool'
#$ARCHS =
#[
# 'x86_64','i386','armel','armhf',
#]
$PACAGES = 
{
	'x86_64'=>
	[
		['main/e/eglibc','libc6-dev_2.17-0ubuntu5_amd64.deb'],
	],
	'i386' =>
	[
		['main/e/eglibc','libc6-dev_2.17-0ubuntu5_i386.deb'],
	],
        'armel' =>
        [
                ['universe/a/armel-cross-toolchain-base/','libc6-dev-armel-cross_2.17-0ubuntu2cross1.101_all.deb'],
        ],
        'armhf' =>
        [
                ['universe/a/armhf-cross-toolchain-base/','libc6-dev-armhf-cross_2.17-0ubuntu2cross1.101_all.deb'],
        ],
}
# download from web
$PACAGES.each do |arch,packs|
	`mkdir -p sdk/#{arch}/`
	packs.each do |pack|
		filename = "sdk/#{arch}/#{pack[1]}"
		if not File.exists?(filename) then
			`wget #{$MIRROR}/#{pack[0]}/#{pack[1]} -O #{filename}`
		end
	end
end
`find sdk -type f -name *.deb`.split(/\n/).each do |deb|
	#`cd #{File.dirname(deb)} && dpkg-deb --show #{File.basename(deb)}
	`dpkg-deb -x #{deb} #{File::dirname(deb)}/`
	`rm -f #{deb} `
end
