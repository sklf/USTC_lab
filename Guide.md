# 如何更新实验室网页中的个人资料

本教程将会指导大家如何更新自己在实验室主页上的个人资料。

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



## 文件存放路径
在本 GitHub 仓库中，所有个人资料均保存在 `content` 路径下面， 其中 `content\en` 存放英文版网页内容， `content\zh` 存放中文版网页内容。 因此为了保证在不同语言环境下网页的统一，每一次更新网站内容时请**务必**同时更新上述两个路径下的相应文件。
## 修改个人资料
所有的普通个人资料均存放在 `content\语种\authors` 路径下，如果路径下没有以你名字命名的文件夹，请自行创建相应文件夹（如 `content\en\authors\ChunyangXie`)，英文版也可以在本地项目根目录下通过以下命令创建：

```
hugo new --kind authors authors/语种/姓名
```
文件夹内应该包含两个文件，即个人资料对应的 `_index.md` 和个人照片 `avatar.jpg`。这里着重介绍如何个性化修改自己的个人资料(`_index.md` 文件）。

`_index.md` 整体结构如下所示：
```
---
# Display name
title: Chunyang Xie
weight: 10


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
# Publications
book:
- Signal Processing


service:
- AE
  
award:
- IEEE Fellow

patent:
- 'Yan Chen, Hongyu Deng, Dongheng Zhang, Yang Hu, SpeedNet: Indoor Speed Estimation with Radio Signals, to appear in IEEE Internet of Things Journal,DOI:10.1109/JIOT.2020.3022071'
- 'Ying He,Yan Chen, Yang Hu, and Bing Zeng, WiFi Vision: Sensing, Recognition, and Detection with Commodity MIMO-OFDM WiFi, to appear in IEEE Internet of Things Journal,DOI:10.1109/JIOT.2020.2989426'
- 'Yan Chen, Xiang Su, Yang Hu, Bing Zeng, Residual Carrier Frequency Offset Estimation and Compensation for Commodity WiFi, to appear in IEEE Transactions on Mobile Computing, DOI:10.1109/TMC.2019.2934106'
  
journal:
- 'Yan Chen, Hongyu Deng, Dongheng Zhang, Yang Hu, SpeedNet: Indoor Speed Estimation with Radio Signals, to appear in IEEE Internet of Things Journal,DOI:10.1109/JIOT.2020.3022071'
- 'Ying He,Yan Chen, Yang Hu, and Bing Zeng, WiFi Vision: Sensing, Recognition, and Detection with Commodity MIMO-OFDM WiFi, to appear in IEEE Internet of Things Journal,DOI:10.1109/JIOT.2020.2989426'

conference:
- 'Yan Chen, Hongyu Deng, Dongheng Zhang, Yang Hu, SpeedNet: Indoor Speed Estimation with Radio Signals, to appear in IEEE Internet of Things Journal,DOI:10.1109/JIOT.2020.3022071'


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
`title` 项修改为自己的名字，注意中英文版的差别。`role` 填写自己当前的身份，如 `PhD student` 或 `博士生`。 `organization` 下的 `name` 填写学校名称，`url` 填写学校官网网址。 `bio` 可以填写简短的自我介绍或者不填。`interests` 填写自己感兴趣的研究方向。`education` 列举自己的教育经历。`patent` 、`journal`、 `cinference`、 `patent` 、`journal`、 `cinference` 分别按实例格式填写相应内容，如果没有，可以注释掉。

`social`类根据需要更新自己的个人主页/github主页/电子邮件等等。注意，`user_groups` 需要从以下类别中选取，否则网页无法正确将你的个人资料分类：
中文版|英文版|
--|:--:|
教职工|Faculty|
博士生|Ph.D. Students|
硕士生|Master Students|
本科生|Undergrad Students|
校友|Alumni|


请注意，`weight` 项为权重项，后面的数值表示排序的权重，越小则在网页上分组内展示越靠前。为了避免顺序混乱，目前暂时采用以下规则：

入学年份|权重区间|
--|:--:|
2018 及以前|1~20|
2019|21~40|
2020|41~60|
2021|61~80|
2022|81~100|

同时需要注意，不同角色分组下的 `weight` **并不冲突**，因此可以放心使用上述规则，同一年份的权重分配原则上先到先得，也可以自行商量分配。

文件最下面为个人介绍，请将中英文介绍分别填写至对应的文件中。

校友部分放在`content\语种\authors\alumni`文件夹下，如需新增请打开文件夹下 `_index.md` 文件，按已有模板进行增减，目前暂不支持展示校友的照片和详细信息。


## 修改项目信息
项目资料存放在 `content\语种\projects` 路径下，如果需要新建项目，请自行建立相应文件夹（如 `content\en\projects\MTrack`)。
文件夹内应**至少** 包含 `index.md`, 即项目的页面资料，最好包含项目的特征图片，即 `featured.jpg/png`。
`index.md` 整体结构如下所示：
```
---
# Documentation: https://wowchemy.com/docs/managing-content/

title: "Digital Health"
weight: 40
summary: 
authors: [Chunyang Xie]
tags: [Pose]
categories: []
date: 2021-08-07T19:30:35+08:00

# Optional external URL for project (replaces project detail page).
external_link: ""

# Featured image
# To use, add an image named `featured.jpg/png` to your page's folder.
# Focal points: Smart, Center, TopLeft, Top, TopRight, Left, Right, BottomLeft, Bottom, BottomRight.
image: 
  caption: ""
  focal_point: ""
  preview_only: false

# Custom links (optional).
#   Uncomment and edit lines below to show custom links.
# links:
# - name: Follow
#   url: https://twitter.com
#   icon_pack: fab
#   icon: twitter

# Slides (optional).
#   Associate this project with Markdown slides.
#   Simply enter your slide deck's filename without extension.
#   E.g. `slides = "example-slides"` references `content/slides/example-slides.md`.
#   Otherwise, set `slides = ""`.
slides: ""
---

Advances in machine learning and contactless sensors have given rise to digital health. We focus on healthcare in the radio world, leveraging the advances in wireless technology in all aspects of healthcare. 
<br>
Our recent research aims to develop contactless healthcare monitoring schemes based on commercial radio systems to achieve physiological information monitoring and health-critical human behaviors sensing under clinical and in-home environments. 
<br>
**Physiological information monitoring:**  We not only precisely measure the respiration and heartbeat rate, but also look deeper into the human body, e.g., monitoring electrocardiogram and blood pressure contactlessly. The proposed hybrid pipeline of signal processing and deep learning framework first extracts human micro-activity measurements from RF signal and then predicts the ECG and blood pressure with an interpretable neural networks that incorporate domain knowledge of RF signal and physiological models.
<br>
**Health-critical human behaviors sensing:** Beyond the physiological information, we also exploit RF signal to sense health-critical human behaviors such as fall. Our RF-based fall detection system utilizes spatio-temporal convolutional neural networks to aggregate information across space and time and extract the corresponding complex spatio-temporal patterns. We address the main challenge in practice fall detection, including dealing with complex falls and fast non-fall movements, generalization to new environments and detecting falls in the presence of other motion. 

```
其中参数部分仅 `title`、`weight` 为必填项，其他如无必要请保持默认即可。 

文件最下方为项目介绍，将对应语种的介绍填写至文件中。
## 修改出版物信息

发表的文章信息存放在 `content\语种\all-publications\allpub.md` 里面，格式如下：
```
---
journal:
- 'iantao Zhou, Zhiqin Liang, Yan Chen, Oscar C. Au, “Security Analysis of Multimedia Encryption Schemes Based on Multiple Huffman Table", IEEE Signal Processing Letters, vol. 14, no. 3, pp. 201-204, March 2007 '
- 'Yan Chen, Yang Hu, Oscar C. Au, Houqiang Li, Chang Wen Chen, “Video Error Concealment Using Spatio-Temporal Boundary Matching and Partial Differential Equation", IEEE Transactions on Multimedia, vol. 10, no. 1, pp. 2-15, Jan. 2008 '
- 'Yan Chen, Oscar C. Au, Xiaopeng Fan, “Simultaneous MAP-Based Video Denoising and Rate-Distortion Optimized Video Encoding", IEEE Transactions on Circuits and Systems for Video Technology (CSVT), vol. 19, no. 1, pp. 15-26, Jan. 2009 '
- 'Xiaopeng Fan, Oscar C. Au, Yan Chen, Jiantao Zhou, Mengyao Ma and Peter H.W. Wong, “Wyner-ziv Based Bidirectionally Decodable Video Coding", Journal of Visual Communication and Image Representation (JVCI), Elsevier, 2009 '

book:
- name: "Yan Chen, Hong Vicky Zhao, Behavior and Evolutionary Dynamics in Crowd Networks: An Evolutionary Game Approach, (132 pages), Springer, 2020"
  cover: cover2.png
- name: Yan Chen, C.Y. Wang, C.X. Jiang, and K.J.R. Liu, Reciprocity, Evolution, and Decision Games in Network and Data Science, (460 pages), Cambridge University Press, 2021
  cover: cover1.jpg

patent:
- 'Oscar C. Au and Yan Chen, ``Rate Distortion Optimization for Video Denoising", US Full Patent Application (12/132769), filed June 4, 2008 (licensed on July 13 2010)'
- 'Oscar C. Au and Yan Chen, "Rate Distortion Optimized Intermode Decision for H.264 Error resilient Video Coding", US Full Patent Application (11/853498), filed Sept. 11, 2007 (licensed on July 13 2010)'
- 'Oscar C. Au and Yan Chen, ``Spatio-Temporal Boundary Matching Algorithm for Temporal Error Concealment", US Full Patent Application (11/750144), filed May 17, 2007 (licensed on July 13 2010)'
- 'Feng Han, K. J. Ray Liu, Yan Chen, “Time-Reversal Wireless System Having Asymmetric Architecture”, PCT Patent Application WO2015023895A1, filed Aug. 14, 2014.'
- 'Yan Chen, Hung-Quoc Duc Lai, Yi Han, Chen Chen, Zhung-Han Wu, K. J. Ray Liu, Katherine L. Hall, “Wireless Positioning Systems”, PCT Patent Application WO2016011433A2, filed July 17, 2015.'
- 'Oscar C. Au and Yan Chen, ``Rate Control and Video Denoising for Noisy Video Data", US Full Patent (US 8982947 B2), granted March 17, 2015'

  
conference:
- 'Yang Hu, Yan Chen, Houqiang Li, Chang Wen Chen, ``An Improved Spatio-Temporal Video Error Concealment Algorithm Using Partial Differential Equation", Proc. SPIE Multimedia Systems and Applications VIII, 2005'
- 'Yan Chen, Xiaoyan Sun, Feng Wu, Zhengkai Liu, ``Spatio-Temporal Video Error Concealment Using Priority-Ranked Region-Matching", Proc. IEEE Int. Conf. Image Processing (ICIP), 2005'
- 'Xiaopeng Fan, Oscar C. Au, Yan Chen, Jiantao Zhou, ``Heegard-Berger Video Coding Using LMMSE Estimator", Pacific-RIM Conference on Multimedia (PCM), 2006'
- 'Carman Yuk, Oscar C. Au, Richard Li, S.Y. Lam, Yan Chen, ``Color Demosaicking using Direction-Consistent Estimation", Proc. IEEE Int. Symposium on Intelligent Signal Processing and Communication Systems (ISPACS), 2006'
- 'Yan Chen, Oscar C. Au, Jiantao Zhou, Xiaopeng Fan, Liwei Guo, ``Decoder-Embedded Temporal Interpolation Using Least Square Optimal Filter (LSOF)", Proc. IEEE Int. Symposium on Intelligent Signal Processing and Communication Systems (ISPACS), 2006'

---

```
请按模板格式将文章信息填写至文件中， 请务必注意`-`符号后面一定要**缩进**。 在增加文章时，为了避免不必要的麻烦，请用**英文的单引号**将每一个条目包裹住。
填写专著 `book` 信息时，将专著封面图片放入仓库根目录下的 `assets\media` 路径下，并将文件名填写至 `cover` 项。


## 本地实时预览
Hugo 支持在本机实时编译预览生成的网页，在终端内进入本地仓库根目录，输入：
```
hugo server -p 端口号
```
浏览器打开网址`127.0.0.1:端口号` 即可实时预览网页。

然后就可以看到网页
