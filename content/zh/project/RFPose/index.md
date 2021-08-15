---
# Documentation: https://wowchemy.com/docs/managing-content/

title: "RFPose:Through-Wall Human Pose Estimation Using Radio Signals"
summary: "Estimating Human Pose using RF signal."
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

url_code: "https://github.com/sklf/RFPose"
url_pdf: "http://openaccess.thecvf.com/content_cvpr_2018/papers/Zhao_Through-Wall_Human_Pose_CVPR_2018_paper.pdf"
url_slides: ""
url_video: "https://youtu.be/HgDdaMy8KNE"

# Slides (optional).
#   Associate this project with Markdown slides.
#   Simply enter your slide deck's filename without extension.
#   E.g. `slides = "example-slides"` references `content/slides/example-slides.md`.
#   Otherwise, set `slides = ""`.
slides: ""
---

RF-Pose provides accurate human pose estimation through walls and occlusions. It leverages the fact that wireless signals in the WiFi frequencies traverse walls and reflect off the human body. It uses a deep neural network approach that parses such radio signals to estimate 2D poses. RF-Pose is trained using state-of-the-art vision model to provide cross-modal supervision. Once trained, RF-Pose uses only the wireless signal for pose estimation. Experimental results show that, when tested on visible scenes, the radio-based system is almost as accurate as the vision-based system used to train it. Yet, unlike vision-based pose estimation, the radio-based system can estimate 2D poses through walls despite never trained on such scenarios.