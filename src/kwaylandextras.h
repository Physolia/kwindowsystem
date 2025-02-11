/*
    This file is part of the KDE libraries
    SPDX-FileCopyrightText: 2021 Aleix Pol <aleixpol@kde.org>
    SPDX-FileCopyrightText: 2023 Nicolas Fella <nicolas.fella@gmx.de>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KWAYLANDEXTRAS_H
#define KWAYLANDEXTRAS_H

#include <QObject>
#include <QWindow>

#include <kwindowsystem_export.h>

/**
 * A collection of functions to do Wayland things
 * @since 6.0
 */
class KWINDOWSYSTEM_EXPORT KWaylandExtras : public QObject
{
    Q_OBJECT

public:
    static KWaylandExtras *self();

    /**
     * Requests an xdg_activation_v1 token for a specific window.
     *
     * @param win window in behalf this request is made
     * @param serial of the event that triggered the request
     * @param app_id identifier of the application that we are launching
     *
     * @see lastInputSerial
     */
    Q_INVOKABLE static void requestXdgActivationToken(QWindow *win, uint32_t serial, const QString &app_id);

    /**
     * Offers the seat's current serial
     */
    Q_INVOKABLE static quint32 lastInputSerial(QWindow *window);

Q_SIGNALS:
    /**
     * Activation @p token to pass to the client.
     *
     * @see requestXdgActivationToken
     */
    void xdgActivationTokenArrived(int serial, const QString &token);

private:
    KWaylandExtras();
    ~KWaylandExtras();

    void *d;
};

#endif
