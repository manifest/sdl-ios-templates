# Minimal SDL iOS Application Template for Xcode 4

A minimal Xcode 4 project template for developing an iOS applications with SDL and C/C++.  
Specifically,

- No definitions of files or functions inside abstract templates, enabling you to easily parse and customize the template.
- No unit test options.
- No family selections for iPad or universal applications. 

### Getting Started

1. Place the directory of this project to the Xcode Template directory, create it if needed.

		$ mkdir -p ~/Library/Developer/Xcode/Templates
		$ git clone https://github.com/manifest/sdl-ios-templates ~/Library/Developer/Xcode/Templates/SDL

2. Use [SDL iOS build script][sdl-ios-framework] to download and build the `SDL.framework`.

3. Copy `SDL.framework` to the `~/Library/Frameworks` directory.
Or place it anywhere, but then not forget to specify that path
in the `Framework Search Paths` property of the Xcode project.

4. Open Xcode and create a new project. Select the template from the iOS pane.

### How to customize

To customize, follow the article ["A minimal project template for Xcode 4"][minimal-template-article].

### License

Minimal SDL iOS Application Template based on [Minimal Template][minimal-template] and is provided under the terms of [the MIT license][license].

[sdl-ios-framework]:https://github.com/manifest/sdl-ios-framework
[minimal-template-article]:http://blog.boreal-kiss.net/2011/03/11/a-minimal-project-template-for-xcode-4
[minimal-template]:https://github.com/borealkiss/Minimal-Template
[license]:http://www.opensource.org/licenses/MIT

