/*
 * Keramik KWin client configuration module
 *
 * Copyright (C) 2002 Fredrik Höglund <fredrik@kde.org>
 *
 * Based on the Quartz configuration module,
 *     Copyright (c) 2001 Karol Szwed <gallium@kde.org>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the license, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __KWIN_KERAMIK_CONFIG_H
#define __KWIN_KERAMIK_CONFIG_H

#include <kconfig.h>

#include "ui_keramikconfig.h"

class KeramikConfigUI : public QWidget, public Ui::KeramikConfigUI
{
public:
  KeramikConfigUI( QWidget *parent ) : QWidget( parent ) {
    setupUi( this );
  }
};



class KeramikConfig: public QObject
{
	Q_OBJECT

	public:
		KeramikConfig( KConfig* conf, QWidget* parent );
		~KeramikConfig();

	// These public signals/slots work similar to KCM modules
	signals:
		void changed();

	public slots:
		void load( const KConfigGroup& conf );	
		void save( KConfigGroup& conf );
		void defaults();

	private:
		KeramikConfigUI *ui;
		KConfig *c;
};


#endif

// vim: set noet ts=4 sw=4: