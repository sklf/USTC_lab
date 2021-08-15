<<<<<<< HEAD
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

=======
---
# Documentation: https://wowchemy.com/docs/managing-content/

title: "MTrack: Tracking Multi-Person Moving
Trajectories and Vital Signs with Radio Signals"
summary: ""
authors: [DonghengZhang]
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

>>>>>>> upstream/dev
我们实施了一个多天线宽带系统，可以提供高分辨率的到达角 (AoA) 和飞行时间 (ToF)。 2D 波束成形器用于将原始无线电信号转换为 AoA-ToF 域。 为了跟踪移动人的轨迹，我们利用人的移动来消除静态多径，并提出一种路径选择算法来估计人的位置并抑制动态多径的干扰。 为了跟踪静态人的生命体征，我们利用静态人的呼吸来消除静态多径，并提出一种基于相关的算法来消除动态多径。 大量实验表明，所提出的 MTrack 系统能够以亚分米级精度跟踪多个移动的人，并且可以估计静态人的呼吸和心跳率，准确率分别为 99.8% 和 98.46%。