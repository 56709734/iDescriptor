/*
 * iDescriptor: A free and open-source idevice management tool.
 *
 * Copyright (C) 2025 Uncore <https://github.com/uncor3>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "creddialog.h"
#include "settingsmanager.h"
#include <QApplication>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

CredDialog::CredDialog(QWidget *parent)
    : QDialog(parent), m_mainLayout(nullptr), m_okButton(nullptr),
      m_titleLabel(nullptr), m_descriptionLabel(nullptr),
      m_dontShowAgainCheckbox(nullptr)
{
    setupUI();
}

CredDialog::~CredDialog() {}

void CredDialog::setupUI()
{
#ifdef WIN32
    setWindowTitle("Windows Credential Manager Access Required");
#else
    setWindowTitle("Secret Service Access Required");
#endif
    setModal(true);
    setMinimumSize(500, 250);
    resize(600, 300);

    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setContentsMargins(20, 20, 20, 20);
    m_mainLayout->setSpacing(15);

    // Title label
#ifdef WIN32
    m_titleLabel = new QLabel("Windows Credential Manager Access Required");
#else
    m_titleLabel = new QLabel("Secret Service Access Required");
#endif
    m_titleLabel->setAlignment(Qt::AlignCenter);
    m_titleLabel->setStyleSheet(
        "font-size: 18px; font-weight: bold; margin-bottom: 10px;");
    m_mainLayout->addWidget(m_titleLabel);

    // Description label
#ifdef WIN32
    QString description =
        "In order to sign in to App Store we use the Windows Credential "
        "Manager "
        "to safely store and retrieve your credentials. You may be prompted to "
        "allow access to the credential manager. "
        "This is a security feature to protect your Apple ID credentials. You "
        "can disable this in Settings.";
#else
    QString description =
        "In order to sign in to App Store we use the Secret Service "
        "(gnome-keyring "
        "or similar) to safely store and retrieve your credentials. You may be "
        "prompted to unlock your keyring or allow access. "
        "This is a security feature to protect your Apple ID credentials. You "
        "can disable this in Settings.";
#endif

    m_descriptionLabel = new QLabel(description);
    m_descriptionLabel->setAlignment(Qt::AlignCenter);
    m_descriptionLabel->setWordWrap(true);
    m_descriptionLabel->setStyleSheet("font-size: 14px; margin: 10px;");
    m_mainLayout->addWidget(m_descriptionLabel);

    m_mainLayout->addStretch();

    m_dontShowAgainCheckbox = new QCheckBox("Don't show this again");
    m_mainLayout->addWidget(m_dontShowAgainCheckbox, 0, Qt::AlignCenter);

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    m_skipSigningInButton = new QPushButton("Skip For Now");
    m_skipSigningInButton->setFixedHeight(40);

    m_okButton = new QPushButton("OK, I understand");
    m_okButton->setDefault(true);
    m_okButton->setFixedHeight(40);

    buttonsLayout->addWidget(m_skipSigningInButton);
    buttonsLayout->addWidget(m_okButton);

    m_mainLayout->addLayout(buttonsLayout, Qt::AlignCenter);

    connect(m_okButton, &QPushButton::clicked, this, &CredDialog::onOkClicked);
    connect(m_skipSigningInButton, &QPushButton::clicked, this,
            &CredDialog::onSkipSigningInClicked);
}

void CredDialog::onOkClicked()
{
    if (m_dontShowAgainCheckbox && m_dontShowAgainCheckbox->isChecked()) {
        SettingsManager::sharedInstance()->setShowKeychainDialog(false);
    }

    accept();
}

void CredDialog::onSkipSigningInClicked()
{
    if (m_dontShowAgainCheckbox && m_dontShowAgainCheckbox->isChecked()) {
        SettingsManager::sharedInstance()->setShowKeychainDialog(false);
    }

    reject();
}
