<!--961032830987546d0e6d54829fc886f6-->

目录(Catalo)

* [ git commit 时 图标使用 --- emoji 指南](#%20git%20commit%20%E6%97%B6%20%E5%9B%BE%E6%A0%87%E4%BD%BF%E7%94%A8%20---%20emoji%20%E6%8C%87%E5%8D%97)
  * [Git在提交时添加Emoji有什么好处](#Git%E5%9C%A8%E6%8F%90%E4%BA%A4%E6%97%B6%E6%B7%BB%E5%8A%A0Emoji%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E5%A4%84)
  * [执行 `git commit` 时使用 emoji 为本次提交打上一个 “标签”, 使得此次 commit 的主要工作得以凸现，也能够使得其在整个提交历史中易于区分与查找。](#%E6%89%A7%E8%A1%8C%20%60git%20commit%60%20%E6%97%B6%E4%BD%BF%E7%94%A8%20emoji%20%E4%B8%BA%E6%9C%AC%E6%AC%A1%E6%8F%90%E4%BA%A4%E6%89%93%E4%B8%8A%E4%B8%80%E4%B8%AA%20%E2%80%9C%E6%A0%87%E7%AD%BE%E2%80%9D%2C%20%E4%BD%BF%E5%BE%97%E6%AD%A4%E6%AC%A1%20commit%20%E7%9A%84%E4%B8%BB%E8%A6%81%E5%B7%A5%E4%BD%9C%E5%BE%97%E4%BB%A5%E5%87%B8%E7%8E%B0%EF%BC%8C%E4%B9%9F%E8%83%BD%E5%A4%9F%E4%BD%BF%E5%BE%97%E5%85%B6%E5%9C%A8%E6%95%B4%E4%B8%AA%E6%8F%90%E4%BA%A4%E5%8E%86%E5%8F%B2%E4%B8%AD%E6%98%93%E4%BA%8E%E5%8C%BA%E5%88%86%E4%B8%8E%E6%9F%A5%E6%89%BE%E3%80%82)
    * [commit 格式](#commit%20%E6%A0%BC%E5%BC%8F)
    * [commit一共由五部分组成：](#commit%E4%B8%80%E5%85%B1%E7%94%B1%E4%BA%94%E9%83%A8%E5%88%86%E7%BB%84%E6%88%90%EF%BC%9A)
    * [emoji 指南 --快览](#emoji%20%E6%8C%87%E5%8D%97%20--%E5%BF%AB%E8%A7%88)
    * [参考](#%E5%8F%82%E8%80%83)

<!--a46263f7a69f33f39fc26f907cdb773a-->
#  git commit 时 图标使用 --- emoji 指南

## Git在提交时添加Emoji有什么好处

![2060608-a2a29c8c9276a39a.png](https://upload-images.jianshu.io/upload_images/9140378-4204d75665f6e56b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/540)

## 执行 `git commit` 时使用 emoji 为本次提交打上一个 “标签”, 使得此次 commit 的主要工作得以凸现，也能够使得其在整个提交历史中易于区分与查找。

截取的 [git emoji](https://github.com/carloscuesta/gitmoji) 快照:
![logo.png](https://upload-images.jianshu.io/upload_images/9140378-e37cd0dd52acaf8d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
***

### commit 格式

`git commit` 时，提交信息遵循以下格式：

```html
:emoji1: :emoji2: 主题

提交信息主体

Ref <###>
```

初次提交示例：

```html
git commit -m ":tada: Initialize Repo"
```

***
### commit一共由五部分组成：

- #### 提交 commit 的类型，包括以下几种
  +  feat: 新功能
  +  fix: 修复问题
  +  docs: 修改文档
  +  style: 修改代码格式，不影响代码逻辑
  +  refactor: 重构代码，理论上不影响现有功能
  +  perf: 提升性能
  +  test: 增加修改测试用例
  +  chore: 修改工具相关（包括但不限于文档、代码生成等）
  +  deps: 升级依赖
- #### 修改文件的范围
  +  doc
  +  middleware
  +  choe
  +  config
  +  plugin
- #### subject
  +  用一句话清楚的描述这次提交都干了点啥
- #### body
  + 其实就是对subject的一种补充，适当的添加一些原因、目的、结果等等，也可以不写
- #### footer
  + 当有非兼容修改(Breaking Change)时必须在这里描述清楚
  + 关联相关 issue，如 Closes #1, Closes #2, #3
  + 如果功能点有新增或修改的，还需要关联文档 doc

***

### emoji 指南 --快览

![一些图标](https://upload-images.jianshu.io/upload_images/9140378-b98a240a916f934d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/640)
***
![一些图标](https://upload-images.jianshu.io/upload_images/9140378-c9daeb3c83f1ee92.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/640)
***
![一些图标](https://upload-images.jianshu.io/upload_images/9140378-6caa71c98d668309.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/640)
***
| emoji | emoji 代码 | commit 说明 |
| :-- | :-- | :-- |
| :art: (调色板) | `:art:` | 改进代码结构/代码格式 |
|:zap: (闪电):racehorse: (赛马)|`:zap:“:racehorse:`| 提升性能 |
| :fire: (火焰) | `:fire:` | 移除代码或文件 |
| :bug: (bug) | `:bug:` | 修复 bug |
| :ambulance: (急救车) | `:ambulance:` | 重要补丁 |
| :sparkles: (火花) | `:sparkles:` | 引入新功能 |
| :memo: (备忘录) | `:memo:` | 撰写文档 |
| :rocket: (火箭) | `:rocket:` | 部署功能 |
| :lipstick: (口红) | `:lipstick:` | 更新 UI 和样式文件 |
| :tada: (庆祝) | `:tada:` | 初次提交 |
| :white_check_mark: (白色复选框) | `:white_check_mark:` | 增加测试 |
| :lock: (锁) | `:lock:` | 修复安全问题 |
| :apple: (苹果) | `:apple:` | 修复 macOS 下的问题 |
| :penguin: (企鹅) | `:penguin:` | 修复 Linux 下的问题 |
| :checkered_flag: (旗帜) | `:checked_flag:` | 修复 Windows 下的问题 |
| :bookmark: (书签) | `:bookmark:` | 发行/版本标签 |
| :rotating_light: (警车灯) | `:rotating_light:` | 移除 linter 警告 |
| :construction: (施工) | `:construction:` | 工作进行中 |
| :green_heart: (绿心) | `:green_heart:` | 修复 CI 构建问题 |
| :arrow_down: (下降箭头) | `:arrow_down:` | 降级依赖 |
| :arrow_up: (上升箭头) | `:arrow_up:` | 升级依赖 |
| :construction_worker: (工人) | `:construction_worker:` | 添加 CI 构建系统 |
| :chart_with_upwards_trend: (上升趋势图) | `:chart_with_upwards_trend:` | 添加分析或跟踪代码 |
| :hammer: (锤子) | `:hammer:` | 重大重构 |
| :heavy_minus_sign: (减号) | `:heavy_minus_sign:` | 减少一个依赖 |
| :whale: (鲸鱼) | `:whale:` | Docker 相关工作 |
| :heavy_plus_sign: (加号) | `:heavy_plug_sign:` | 增加一个依赖 |
| :wrench: (扳手) | `:wrench:` | 修改配置文件 |
| :globe_with_meridians: (地球) | `:globe_with_meridians:` | 国际化与本地化 |
| :pencil2: (铅笔) | `:pencil2:` | 修复 typo |

***

### 参考

*   [gitmoji](https://github.com/carloscuesta/gitmoji/)
*   [An emoji guide for your commit messages](https://gitmoji.carloscuesta.me/)
*   [styleguide-git-commit-message](https://github.com/slashsBin/styleguide-git-commit-message)
*   [atom git commit messages guide](https://github.com/atom/atom/blob/master/CONTRIBUTING.md#git-commit-messages)
*   [emoji-cheat-sheet](http://www.webpagefx.com/tools/emoji-cheat-sheet/)
*   [程序员提交代码的 emoji 指南——原来表情文字不能乱用](https://www.h5jun.com/post/gitmoji.html)

***