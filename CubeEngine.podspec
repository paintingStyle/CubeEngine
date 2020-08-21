#
# Be sure to run `pod lib lint CubeEngine.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
# pod trunk push CubeEngine.podspec --allow-warnings --verbose

Pod::Spec.new do |s|
	s.name             = 'CubeEngine'
	s.version          = '3.0.4' # 0.2+言见项目使用，0.3+司派项目使用
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

	s.source_files = 'CubeEngine/Classes/include/**/*', 'CubeEngine/Libraries/*.{ast}','CubeEngine/ffmpeg/include/**/*'
	s.xcconfig  =  {'OTHER_LDFLAGS' => '-ObjC' }
	s.vendored_libraries = 'CubeEngine/Libraries/*.a'
	s.public_header_files = 'CubeEngine/Classes/include/**/*.h'
	s.frameworks = 'UIKit','AVFoundation','CoreMotion'
	s.libraries = 'c++','c'
	s.dependency 'SPWebRTC'
	s.dependency 'SPSocketIO'
end


# $ git add .
# $ git commit -m '编辑spec文件'
# $ git remote add origin https://gitlab.com/ModulePlugin/DRCategories.git #添加远端仓库
# $ git push origin master  #提交到远端
# $ git tag -m "first release" "0.1.0" (要与DRCategories.podspec文件中的tag值保持一致)
# $ git push --tags     #推送tag到远端仓库
