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

#pragma once

#include <QUrl>
#include <QWidget>
#include <QWebEngineProfile>

namespace Ui
{
    class WebWindow;
}

namespace f1x
{
    namespace openauto
    {
        namespace autoapp
        {
            namespace ui
            {

                class WebWindow : public QWidget
                {
                Q_OBJECT
                public:
                    explicit WebWindow(QWidget *parent = nullptr);
                    ~WebWindow() override;

                private slots:
                    void onExit();
                    void onHome();


                private:
                    void showEvent(QShowEvent* event);
                    void load();
                    QUrl youtubeUrl;
                    Ui::WebWindow* ui_;
                };

            }
        }
    }
}
