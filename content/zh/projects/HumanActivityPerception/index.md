---
# Documentation: https://wowchemy.com/docs/managing-content/

title: "Human Activity Perception and Imaging Using Radio Signals"
weight: 10
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

Human Activity Perception and Imaging Using Radio Signals
In recent years, building radio sensing systems to perceive and understand the activities of humans has drawn increasing attention, mainly due to the non-intrusive and privacy-preserving characteristics of radio signals. Various systems have been designed to track the human's position, actions, and vital signs by analyzing the radio signals reflected off the human body. However, most existing works can only predict rough human information. In this project, we build a multimodal system to enable the fine-grained human activity perception and imaging using radio signals, which consists of three major components: data collection, RF signal processing, and deep learning models. The data collection component collects human activity images from optical cameras and corresponding radio signals from RF devices. The RF signal processing component transforms the radio signals to the signal amplitude heatmaps. The deep learning models can generate human pose keypoints, pose segmentation, or human activity images based on the radio signal heatmaps. Furthermore, to train and test our proposed system, we create a cross-modal dataset, i.e., RFVisionData.
