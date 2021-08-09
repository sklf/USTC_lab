# 如何更新实验室网页中的个人资料
本教程将会一步步指导大家如何更新自己在实验室主页上的个人资料。请注意，本项目基于 [Hugo](https://github.com/gohugoio/hugo) 和 [Wowchemy's Research Group Template](https://wowchemy.com/templates/) 开发而成，设计理念受到博客 [《How to Build Academic Website for Research Group in 2021》](https://jedyang.com/post/how-to-build-academic-research-group-website-in-2021/) 启发。

- [如何更新实验室网页中的个人资料](#如何更新实验室网页中的个人资料)
  - [安装必要软件](#安装必要软件)
  - [如何参与更新](#如何参与更新)
  - [文件存放路径](#文件存放路径)
  - [修改个人资料](#修改个人资料)
  - [修改项目信息](#修改项目信息)
  - [修改出版物信息](#修改出版物信息)
  - [本地实时预览](#本地实时预览)

## 安装必要软件
Windows系统请执行以下步骤:
1. 打开 Powershell 终端，输入以下命令并按回车：
   ```
   Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
   iwr -useb get.scoop.sh | iex
   ```
   如果显示`Do you want to change the execution policy?` 输入`Y`即可。
2. 安装 Hugo 及其依赖：
   ```
   scoop install git go hugo-extended
   ```
其他系统请参照 [《Intsall prerequisites》](https://wowchemy.com/docs/getting-started/install-hugo-extended/#prerequisites)


## 如何参与更新
1. Fork 此 GitHub 仓库 `https://github.com/sklf/USTC_lab.git`
2. git clone 这个fork的项目到本地
   ```
   git clone 新的GitHub地址
   ```
3. 添加上游仓库
    1. 进入本地仓库目录下，执行以下操作，将上游仓库连接到本地仓库，即我们fork的源地址：
        ```
        git remote add upstream https://github.com/sklf/USTC_lab.git
        ```
        将上游仓库设置为你的 `upstream`。 
    2. 这个命令执行后，没有任何返回信息；所以再次执行命令 `git remote -v` 检查是否成功。如果成功，应显示以下信息：
        ```
        origin  https://github.com/你的ID/USTC_lab.git (fetch)
        origin  https://github.com/你的ID/USTC_lab.git (push)
        upstream        https://github.com/sklf/USTC_lab.git (fetch)
        upstream        https://github.com/sklf/USTC_lab.git (push)
        ```
    3. 执行命令 `git status` 检查本地是否有未提交的修改。如果有，则把你本地的有效修改，先从本地仓库推送到你的github仓库。最后再执行一次 `git status` 检查本地已无未提交的修改。
        ```
        git add -A 或者 git add filename
        git commit -m "your note"
        git push origin master
        git status
        ```

4. 更新个人资料
   1. 执行命令 `git checkout dev` 切换到 `dev`分支, 如果`upstream` 仓库有更新，请执行`ii、iii、iv`步骤。
   2. 执行命令` git fetch upstream dev` 抓取 `upstream` 原仓库`dev` 分支的更新。
   3. 执行命令 `git merge upstream/dev` 合并远程的`dev`分支。
   4. 将更新发送到自己的 GitHub 仓库里 `git push origin dev`
   5. 在本地仓库`dev`分支下修改个人资料，提交 commit 并 pull 到自己fork 的 GitHub 仓库中：
        ```
        git add -A 或者 git add filename
        git commit -m "your note"
        git push origin dev
        git status
       ```
    6. 在 自己 fork 的 GitHub 仓库主页点击 `Pull requests` 按钮，选择将`dev`的内容 merge 到 `upstream` 仓库的`dev`分支上，写上PR摘要，提交申请。
    
5. 在本地仓库自己的分支下修改个人资料，提交 commit 并 pull 到自己fork 的 GitHub 仓库中，在 GitHub 仓库主页点击 `Pull requests` 按钮，选择将自己分支的内容 merge 到 `upstream` 仓库的`dev`分支上，写上PR摘要，提交申请。





## 文件存放路径
在本 GitHub 仓库中，所有个人资料均保存在 `content` 路径下面， 其中 `content\en` 存放英文版网页内容， `content\zh` 存放中文版网页内容。 因此为了保证在不同语言环境下网页的统一，每一次更新网站内容时请**务必**同时更新上述两个路径下的相应文件。
## 修改个人资料
所有的普通个人资料均存放在 `content\语种\authors` 路径下，如果路径下没有以你名字命名的文件夹，请自行创建相应文件夹（如 `content\en\authors\ChunyangXie`)，英文版可以在本地项目根目录下通过以下命令创建：

```
hugo new --kind authors authors/语种/姓名
```
文件夹内应该包含两个文件，即个人资料对应的 `_index.md` 和个人照片 `avatar.jpg`。这里着重介绍如何个性化修改自己的个人资料(`_index.md` 文件）。

`_index.md` 整体结构如下所示：
```
---
# Display name
title: Chunyang Xie

# Is this the primary user of the site?
superuser: false

# Role/position
role: PhD student of Artificial Intelligence

# Organizations/Affiliations
organizations:
- name: UESTC
  url: ""

# Short bio (displayed in user profile at end of posts)
bio: My research interests include distributed robotics, mobile computing and programmable matter.

interests:
- Artificial Intelligence
- Computational Linguistics
- Information Retrieval

education:
  courses:
  - course: PhD in Artificial Intelligence
    institution: Stanford University
    year: 2012
  - course: MEng in Artificial Intelligence
    institution: Massachusetts Institute of Technology
    year: 2009
  - course: BSc in Artificial Intelligence
    institution: Massachusetts Institute of Technology
    year: 2008

# Social/Academic Networking
# For available icons, see: https://sourcethemes.com/academic/docs/page-builder/#icons
#   For an email link, use "fas" icon pack, "envelope" icon, and a link in the
#   form "mailto:your-email@example.com" or "#contact" for contact widget.
social:
- icon: envelope
  icon_pack: fas
  link: 'mailto:ChunyangXie@std.uestc.edu.cn'
# - icon: twitter
#   icon_pack: fab
#   link: https://twitter.com/GeorgeCushen
# - icon: google-scholar
#   icon_pack: ai
#   link: https://scholar.google.co.uk/citations?user=sIwtMXoAAAAJ
- icon: github
  icon_pack: fab
  link: https://github.com/sklf
# Link to a PDF of your resume/CV from the About widget.
# To enable, copy your resume/CV to `static/files/cv.pdf` and uncomment the lines below.
# - icon: cv
#   icon_pack: ai
#   link: files/cv.pdf

# Enter email to display Gravatar (if Gravatar enabled in Config)
email: ""

# Highlight the author in author lists? (true/false)
highlight_name: false

# Organizational groups that you belong to (for People widget)
#   Set this to `[]` or comment out if you are not using People widget.
user_groups:
- Ph.D. Students
---

Nelson Bighetti is a professor of artificial intelligence at the Stanford AI Lab. His research interests include distributed robotics, mobile computing and programmable matter. He leads the Robotic Neurobiology group, which develops self-reconfiguring robots, systems of self-organizing robots, and mobile sensor networks.

Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed neque elit, tristique placerat feugiat ac, facilisis vitae arcu. Proin eget egestas augue. Praesent ut sem nec arcu pellentesque aliquet. Duis dapibus diam vel metus tempus vulputate.

```
`title` 项修改为自己的名字，注意中英文版的差别。`role` 填写自己当前的身份，如 `PhD student` 或 `博士生`。 `organization` 下的 `name` 填写学校名称，`url` 填写学校官网网址。 `bio` 可以填写简短的自我介绍或者不填。`interests` 填写自己感兴趣的研究方向。`education` 列举自己的教育经历。`social`类根据需要更新自己的个人主页/github主页/电子邮件等等。注意，`user_groups` 需要从以下类别中选取，否则网页无法正确将你的个人资料分类：
中文版|英文版|
--|:--:|
教职工|Faculty|
博士后|Postdocs|
博士生|Ph.D. Students|
硕士生|Master Students|
本科生|Undergrad Students|
校友|Alumni|

文件最下面为个人介绍，请将中英文介绍分别填写至对应的文件中。
## 修改项目信息
项目资料存放在 `content\语种\project` 路径下，如果需要新建项目，请自行建立相应文件夹（如 `content\en\project\MTrack`)，英文版可以在本地项目根目录下通过以下命令创建：

```
hugo new --kind  --kind project project/项目名称
```
文件夹内应**至少** 包含 `index.md`, 即项目的页面资料，最好包含项目的特征图片，即 `featured.jpg/png`。
`_index.md` 整体结构如下所示：
```
---
# Documentation: https://wowchemy.com/docs/managing-content/

title: "MTrack: Tracking Multi-Person Moving
Trajectories and Vital Signs with Radio Signals"
summary: ""
authors: [Dongheng Zhang]
tags: [object track]
categories: []
date: 2021-08-07T19:45:56+08:00

# Optional external URL for project (replaces project detail page).
external_link: ""

# Featured image
# To use, add an image named `featured.jpg/png` to your page's folder.
# Focal points: Smart, Center, TopLeft, Top, TopRight, Left, Right, BottomLeft, Bottom, BottomRight.
image:
  caption: "framework"
  focal_point: ""
  preview_only: false

# Custom links (optional).
#   Uncomment and edit lines below to show custom links.
links:
- name: Follow
  url: https://twitter.com
  icon_pack: fab
  icon: twitter

social:
- icon: envelope
  icon_pack: fas
  link: 'mailto:ChunyangXie@std.uestc.edu.cn'

url_code: ""
url_pdf: ""
url_slides: ""
url_video: ""

# Slides (optional).
#   Associate this project with Markdown slides.
#   Simply enter your slide deck's filename without extension.
#   E.g. `slides = "example-slides"` references `content/slides/example-slides.md`.
#   Otherwise, set `slides = ""`.
slides: ""
---

We propose a human sensing system with radio signals, MTrack, for in-home healthcare, which is capable of tracking the trajectories of moving persons and vital signs of static persons under the multi-person scenarios. To achieve this, we implement a multi-antenna wideband system that can provide high-resolution angle of arrival (AoA) and time of flight (ToF). A 2D beamformer is utilized to transform the raw radio signals into the AoA-ToF domain. To track the trajectories of moving persons, we leverage the movement of persons to cancel static multipaths and propose a path selection algorithm to estimate the locations of human and suppress the interferences from dynamic multipaths. To track the vital signs of static persons, we utilize the breath of static persons to eliminate static multipaths and propose a correlation-based algorithm to eliminate dynamic multipaths. Extensive experiments show that the proposed MTrack system is capable of tracking multiple moving persons with sub-decimeter level accuracy, and can estimate the breath and heartbeat rate of static persons with median accuracy of 99.8% and 98.46%, respectively.
```
其中`authors`项填写项目参与者的姓名，请保证与个人资料里的名字一致，这样可以建立项目与成员间的联系。`links` 和 `social` 类下请根据自身情况修改相关信息。

文件最下方为项目介绍，将对应语种的介绍填写至文件中。
## 修改出版物信息
出版物信息
发表的文章信息存放在 `content\语种\publication` 下面。每篇文章请存放在`姓名-文章关键字`文件夹下，如 `dongheng-MTrack`文件夹，英文版可以在本地项目根目录下通过以下命令创建：
```
hugo new --kind publication publication/语种/姓名-文章关键字
```
每个文件夹下建议包含三个文件：
- `cite.bib`: 存放引用信息，可以通过重命名已有的bibtex文件得到，格式如下：
```
@article{9203899,
 author = {Zhang, Dongheng and Hu, Yang and Chen, Yan},
 doi = {10.1109/JIOT.2020.3025820},
 journal = {IEEE Internet of Things Journal},
 number = {5},
 pages = {3904-3914},
 title = {MTrack: Tracking Multiperson Moving Trajectories and Vital Signs With Radio Signals},
 volume = {8},
 year = {2021}
}
```
-`featured.jpg\png`: 文章的介绍图。

-`index.md`: 文章的具体信息，格式如下：
```
---
# Documentation: https://wowchemy.com/docs/managing-content/

title: 'MTrack: Tracking Multiperson Moving Trajectories and Vital Signs With Radio
  Signals'
subtitle: ''
summary: ''
authors:
- Dongheng Zhang
- Yang Hu
- Yan Chen
tags: []
categories: []
date: '2021-01-01'
lastmod: 2021-08-07T21:51:28+08:00
featured: false
draft: false

# Featured image
# To use, add an image named `featured.jpg/png` to your page's folder.
# Focal points: Smart, Center, TopLeft, Top, TopRight, Left, Right, BottomLeft, Bottom, BottomRight.
image:
  caption: ''
  focal_point: ''
  preview_only: false

# Custom links (optional).
#   Uncomment and edit lines below to show custom links.
#links:
#- name: Follow
#  url: https://twitter.com
#  icon_pack: fab
#  icon: twitter

social:
- icon: envelope
  icon_pack: fas
  link: 'mailto:eezdh@std.uestc.edu.cn'

url_code: ""
url_pdf: ""
url_slides: ""
url_video: ""

# Slides (optional).
#   Associate this project with Markdown slides.
#   Simply enter your slide deck's filename without extension.
#   E.g. `slides = "example-slides"` references `content/slides/example-slides.md`.
#   Otherwise, set `slides = ""`.
slides: ""


# Projects (optional).
#   Associate this post with one or more of your projects.
#   Simply enter your project's folder or file name without extension.
#   E.g. `projects = ["internal-project"]` references `content/project/deep-learning/index.md`.
#   Otherwise, set `projects = []`.
projects: ["MTrack"]
publishDate: '2021-08-07T13:51:27.707795Z'
# Publication type.
# Legend: 0 = Uncategorized; 1 = Conference paper; 2 = Journal article;
# 3 = Preprint / Working Paper; 4 = Report; 5 = Book; 6 = Book section;
# 7 = Thesis; 8 = Patent
publication_types:
- '2'
abstract: 'we implement a multi-antenna wideband system that can provide high-resolution angle of arrival (AoA) and time of flight (ToF). A 2D beamformer is utilized to transform the raw radio signals into the AoA-ToF domain. To track the trajectories of moving persons, we leverage the movement of persons to cancel static multipaths and propose a path selection algorithm to estimate the locations of human and suppress the interferences from dynamic multipaths. To track the vital signs of static persons, we utilize the breath of static persons to eliminate static multipaths and propose a correlation-based algorithm to eliminate dynamic multipaths. Extensive experiments show that the proposed MTrack system is capable of tracking multiple moving persons with sub-decimeter level accuracy, and can estimate the breath and heartbeat rate of static persons with median accuracy of 99.8% and 98.46%, respectively.'
publication: '*IEEE Internet of Things Journal*'
doi: 10.1109/JIOT.2020.3025820
---

```
其中，`draft=false` 代表可以展现在网页上，`true` 则代表网页端不会展示这篇文章，如果此文章对应已有的项目，可以在`project`项中填写项目的名称建立联系。


## 本地实时预览
Hugo 支持在本机实时编译预览生成的网页，在终端内进入本地仓库根目录，输入：
```
hugo server -p 端口号
```
浏览器打开网址`127.0.0.1:端口号` 即可实时预览网页。
