#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

#include "iDescriptor-ui.h"
#include "responsiveqlabel.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QWidget>

class WelcomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWidget(QWidget *parent = nullptr);

private:
    void setupUI();
    ZLabel *createStyledLabel(const QString &text, int fontSize = 0,
                              bool isBold = false);

    QVBoxLayout *m_mainLayout;
    ZLabel *m_titleLabel;
    ZLabel *m_subtitleLabel;
    ResponsiveQLabel *m_imageLabel;
    ZLabel *m_instructionLabel;
    ZLabel *m_githubLabel;
};

#endif // WELCOMEWIDGET_H