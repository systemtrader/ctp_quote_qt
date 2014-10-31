#include<stdio.h>
#include<stdlib.h> 
#include<Windows.h>

#include "mainwindow.h"
#include <QApplication>


#include"ctp_quote.h"

#include"ctp/ThostFtdcMdApi.h"
#include"ctp/ThostFtdcTraderApi.h"

#include"gpp_qt/cfg/cfg.h"
#include"gpp_qt/bar/bar.h"
#include"gpp_qt/bar/bars.h"
#include"gpp_qt/bar/bars_manage.h"
#include"gpp_qt/wtimer/wtimer.h"


cfg simu_cfg;
bars_manage simu_bars_manage;
wtimer tm;
CThostFtdcMdApi * pUserApi;


MainWindow * mw;
QApplication * qa;

int main(int argc, char *argv[])
{
	simu_cfg.setcfgfile("c:/cfg/simu_trade.cfg");
	simu_bars_manage.addbarlist(simu_cfg.getparam("INSTRUMENT_ID"));

    QApplication a(argc, argv);
    MainWindow w;
    qa=&a;
    mw=&w;
    w.show();
	
	pUserApi=CThostFtdcMdApi::CreateFtdcMdApi();
	ctp_quote simu_quote;
	simu_quote.init();		
	simu_quote.login(pUserApi);

	return a.exec();
}
