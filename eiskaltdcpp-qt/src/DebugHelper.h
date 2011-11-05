/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef DEBUGHELPER_H
#define DEBUGHELPER_H

#ifndef QT_NO_DEBUG

#include <QtDebug>
class DebugHelper{
public:
    DebugHelper(){}
    
    virtual ~DebugHelper(){
        if (whitespace.size() >= 2)
            whitespace.remove(0, 2);
    }
    
    const char* operator << (const QString &out){
        QString ret = whitespace + out;
        
        whitespace += "  ";
        
        return qPrintable(ret);
    }    
private:
    static QString whitespace;
};

QString DebugHelper::whitespace = "";

#define DEBUG_BLOCK DebugHelper _dbg_helper_; \
                    qDebug() << (_dbg_helper_ << Q_FUNC_INFO);
                    
#else // QT_NO_DEBUG

#define DEBUG_BLOCK

#endif //QT_NO_DEBUG
                    
#endif // DEBUGHELPER_H