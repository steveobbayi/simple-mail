/*
  Copyright (c) 2011-2012 - Tőkés Attila
  Copyright (C) 2015 Daniel Nicoletti <dantti12@gmail.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  See the LICENSE file for more details.
*/

#ifndef MIMEPART_H
#define MIMEPART_H

#include <QtCore/QMetaType>

#include "mimecontentformatter.h"

#include "smtpexports.h"

class MimePartPrivate;
class SMTP_EXPORT MimePart
{
    Q_DECLARE_PRIVATE(MimePart)
public:
    enum Encoding {        
        _7Bit,
        _8Bit,
        Base64,
        QuotedPrintable
    };

    MimePart();
    virtual ~MimePart();

    QString header() const;
    QByteArray content() const;

    void setContent(const QByteArray &content);
    void setHeader(const QString &header);

    void addHeaderLine(const QString &line);

    void setContentId(const QString &cId);
    QString contentId() const;

    void setContentName(const QString &name);
    QString contentName() const;

    void setContentType(const QString &cType);
    QString contentType() const;

    void setCharset(const QString &charset);
    QString charset() const;

    void setEncoding(Encoding enc);
    Encoding encoding() const;

    MimeContentFormatter *contentFormatter();

    virtual QString toString();

    virtual void prepare();

protected:
    MimePartPrivate *d_ptr;
};

#endif // MIMEPART_H
