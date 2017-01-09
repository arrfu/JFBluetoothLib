Pod::Spec.new do |s|

s.name         = "LXWiFiLibrary"          #导入pod后的名称
s.version      = "0.0.5"                     #当前版本号
s.summary      = "A custom iOS Bluetooth Library for smart devices"   #简介
s.description  = <<-DESC                     #详细介绍
This library is just for the devices which are from Actions Semi.
DESC

s.homepage     = "http://192.168.11.20/gitlab/snaillove/platform-ios-libraries" #主页, 必须为可访问地址, 否则会验证失败
s.license      = { :type => 'Apache', :file => 'LICENSE' }   #开源协议证书

s.author             = { "ifeegoo" => "root@ifeegoo.com" }  #作者信息
s.social_media_url   = "https://www.ifeegoo.com"

s.platform     = :ios, "7.0"                 #支持平台及版本(以上)
#s.ios.deployment_target = "7.0"             #同上, 多平时使用.
#s.resource_bundles = {'PodTestLibrary' => ['Pod/Assets/*.png']}   #资源文件地址
s.source       = { :git => "https://github.com/arrfu/JFBluetoothLib.git", :tag => s.version.to_s }        #项目地址, 不支持ssh
s.source_files  = "wifi/**/*"   #源代码文件地址,表示platform-ios-libraries/bluetooth及其子文件夹下的所有.h和.m文件

s.requires_arc = true                        #是否支持ARC

# s.framework = "SomeFramework"              #指定导入的framework
# s.frameworks = "SomeFramework", "AnotherFramework"   #多个framework, 或写多个s.framework
# s.library = "iconv"                        #指定导入的库, 如sqlite3 frameworks
# s.libraries = "iconv", "xml2"              #指定多个导入的库
# s.dependency "JSONKit", "~> 1.4"           #指定依赖关系
# s.dependencys "AFNetworking", "~> 2.2.4", "JSONKit", "~> 1.4"   #多个依赖关系


end
