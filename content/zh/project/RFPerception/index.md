---
# Documentation: https://wowchemy.com/docs/managing-content/

title: "基于无线信号的人体感知与成像"
summary: ""
authors: [俞聪, 武治]
tags: [pose, segmentation, imaging]
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

近年来，由于无线信号的非侵入性和隐私保护特性，构建无线传感系统以感知和理解人体活动受到越来越多的关注。目前已有的各种系统通过分析人体反射的无线信号来跟踪人体的位置、动作和生命体征。然而，大多数现有方法只能预测粗略的人体信息。在这个项目中，我们构建了一个多模态系统，以使用无线信号实现细粒度的人体活动感知和成像，该系统由三个主要部分组成：数据收集、射频信号处理和深度学习模型。数据收集组件收集来自光学相机的人体活动图像和来自无线设备的相应无线信号。 射频信号处理组件将无线信号转换为信号幅度热力图。深度学习模型可以基于无线信号热力图生成人体姿势关键点、姿势分割或人体活动图像。此外，为了训练和测试我们提出的系统，我们制作了一个跨模态数据集，即RFVisionData。