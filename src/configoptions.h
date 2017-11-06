/*
 *
 *  Copyright (c) 2017
 *  name : Francis Banyikwa
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONFIGOPTIONS_H
#define CONFIGOPTIONS_H

#include <QDialog>
#include <QCloseEvent>
#include <QMenu>

#include <functional>
#include <utility>
#include <vector>
#include "secrets.h"

namespace Ui {
class configOptions ;
}

class configOptions : public QDialog
{
	Q_OBJECT
public:
	static void instance( QWidget * e,
			      secrets& a,
			      QMenu * m,
			      std::function< void() > s,
			      std::function< void( QAction * ) > z )
	{
		new configOptions( e,a,m,std::move( s ),std::move( z ) ) ;
	}

	explicit configOptions( QWidget * parent,
				secrets&,
				QMenu *,
				std::function< void() >,
				std::function< void( QAction * ) > ) ;
	~configOptions() ;
private:
	void HideUI() ;
	void closeEvent( QCloseEvent * ) ;
	Ui::configOptions * m_ui ;
	std::function< void() > m_function ;
	std::function< void( QAction * ) > m_updateLanguage ;
	secrets& m_secrets ;
	std::vector< std::pair< QAction *,const char * > > m_actionPair ;
};

#endif // CONFIGOPTIONS_H