/*
*  This file is part of openauto project.
*  Copyright (C) 2018 f1x.studio (Michal Szwaj)
*
*  openauto is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 3 of the License, or
*  (at your option) any later version.

*  openauto is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with openauto. If not, see <http://www.gnu.org/licenses/>.
*/

#include <f1x/openauto/autoapp/UI/WebWindow.hpp>
#include "ui_webwindow.h"

namespace f1x {
    namespace openauto {
        namespace autoapp {
            namespace ui {

                WebWindow::WebWindow(QWidget *parent)
                        : QWidget(parent), ui_(new Ui::WebWindow) {
                    youtubeUrl = QUrl("https://youtube.com/");
                    ui_->setupUi(this);

                    //QWebEngineProfile *profile = QWebEngineProfile::defaultProfile();
                    //profile->setHttpUserAgent("myAgent");
                    QWebEngineProfile::defaultProfile()->setHttpUserAgent("Mozilla/5.0 (Linux; Android 9; G8341) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.149 Mobile Safari/537.36");
                    connect(ui_->webHomeButton, &QPushButton::clicked, this, &WebWindow::onHome);
                    connect(ui_->webExitButton, &QPushButton::clicked, this, &WebWindow::onExit);
                }

                WebWindow::~WebWindow() {
                    delete ui_;
                }

                void WebWindow::onExit() {
                    youtubeUrl = ui_->webEngineView->url();
                    ui_->webEngineView->setUrl(QUrl("about:blank"));
                    this->close();
                }

                void WebWindow::onHome() {
                    ui_->webEngineView->setUrl(QUrl("https://youtube.com"));
                }

                void WebWindow::showEvent(QShowEvent *event) {
                    QWidget::showEvent(event);
                    this->load();
                }

                void WebWindow::load() {
                    ui_->webEngineView->setUrl(youtubeUrl);
                }

            }
        }
    }
}
