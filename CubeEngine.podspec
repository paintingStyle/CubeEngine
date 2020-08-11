#
# Be sure to run `pod lib lint CubeEngine.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
# pod trunk push CubeEngine.podspec --allow-warnings --verbose

Pod::Spec.new do |s|
	s.name             = 'CubeEngine'
	s.version          = '3.0.3' # 0.2+言见项目使用，0.3+司派项目使用
	s.summary          = 'shixinyun CubeEngine'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/paintingStyle/CubeEngine'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'paintingStyle' => 'renshuangfu@spap.com' }
  s.source           = { :git => 'https://github.com/paintingStyle/CubeEngine.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

	s.source_files = 'CubeEngine/Classes/include/**/*', 'CubeEngine/Libraries/*.{ast}','CubeEngine/ffmpeg/include/**/*','CubeEngine/Frameworks/WebRTC/**/*.h'
	s.xcconfig  =  {'OTHER_LDFLAGS' => '-ObjC' }
	s.vendored_libraries = 'CubeEngine/Libraries/*.a'
	s.vendored_frameworks = 'CubeEngine/Frameworks/*.framework'
	s.public_header_files = 'CubeEngine/Classes/include/**/*.h',"CubeEngine/Frameworks/WebRTC.framework/Headers/**/*.h"
	s.frameworks = 'UIKit','AVFoundation','CoreMotion'
	s.libraries = 'c++','c'
end
