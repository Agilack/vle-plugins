/*
 * This file is part of VLE, a framework for multi-modeling, simulation
 * and analysis of complex dynamical systems.
 * http://www.vle-project.org
 *
 * Copyright (c) 2014 INRA
 *
 */
#ifndef MODELER_DUMMY_H
#define MODELER_DUMMY_H

#include <QObject>
#include <QSettings>
#include <vle/gvle2/vlevpz.h>
#include <vle/gvle2/plugin_modeler.h>
#include <vle/gvle2/logger.h>
#include "tabwidget.h"
#include "editwidget.h"

class ModelerDummy : public PluginModeler
{
    Q_OBJECT
    Q_INTERFACES(PluginModeler)

public:
    ModelerDummy();
    ~ModelerDummy();
    QString getname();
    QString getData(QString className);
public:
    bool     useCustomMainTab();
    QWidget *getMainTabWidget();
    void     delWidget();
    QWidget *addNewWidget();
    QWidget *addEditWidget();
    void setSettings(QSettings *s);
    void setLogger(Logger *logger);

public slots:
    void onNameChange(QString name);
    void onSaveClass();
signals:
    void nameChanged(QWidget *tab, QString name);
    void saveClass(QString name);

private:
    QString             mName;
    QSettings         * mSettings;
    Logger            * mLogger;
    TabWidget         * mWidgetTab;
    QList<EditWidget *> mWidgetEdit;
};

#endif // MODELER_DUMMY_H
