/*
 * Dibbler - a portable DHCPv6                                               
 *                                                                           
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>                           
 *          Marek Senderski <msend@o2.pl>                                    
 *                                                                           
 * released under GNU GPL v2 or later licence                                
 *                                                                           
 * $Id: SrvParsClassOpt.h,v 1.6 2004-09-28 20:12:39 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.5  2004/09/03 23:20:23  thomson
 * RAPID-COMMIT support fixed. (bugs #50, #51, #52)
 *
 * Revision 1.4  2004/07/05 00:12:30  thomson
 * Lots of minor changes.
 *
 * Revision 1.3  2004/06/28 22:37:59  thomson
 * Minor changes.
 *
 */

class TSrvParsClassOpt;
#ifndef TSRVPARSCLASS_H
#define TSRVPARSCLASS_H

#include <string>
#include "StationID.h"
#include "DHCPConst.h"
#include "Container.h"
#include "SmartPtr.h"
#include "StationRange.h"
#include "IPv6Addr.h"

class TSrvParsClassOpt
{
 public:
    TSrvParsClassOpt(void);
    ~TSrvParsClassOpt(void);

    //T1,T2,Valid,Prefered time routines
    void setT1Beg(unsigned long t1);
    void setT1End(unsigned long t1);
    unsigned long getT1Beg();
    unsigned long getT1End();

    void setT2Beg(unsigned long t2);
    void setT2End(unsigned long t2);
    unsigned long getT2Beg();
    unsigned long getT2End();
    
    void setPrefBeg(unsigned long pref);
    void setPrefEnd(unsigned long pref);
    unsigned long getPrefBeg();
    unsigned long getPrefEnd();

    void setValidEnd(unsigned long valid);
    void setValidBeg(unsigned long valid);
    unsigned long getValidEnd();
    unsigned long getValidBeg();
        
    //Rejected clients access routines
    void addRejedClnt(SmartPtr<TStationRange> addr);
    void firstRejedClnt();
    SmartPtr<TStationRange> getRejedClnt();
    void setRejedClnt(TContainer<SmartPtr<TStationRange> > *rejedClnt);
    
    //Accepted clients access routines
    void addAcceptClnt(SmartPtr<TStationRange> addr);
    void firstAcceptClnt();
    SmartPtr<TStationRange> getAcceptClnt();
    void setAcceptClnt(TContainer<SmartPtr<TStationRange> > *acceptClnt);
    
    //Pool access routines
    void addPool(SmartPtr<TStationRange> addr);
    void firstPool();
    SmartPtr<TStationRange> getPool();
    void setPool(TContainer<SmartPtr<TStationRange> > *pool);
    long countPool();

    // leases count
    void setClassMaxLease(unsigned long maxClntLeases);
    unsigned long getClassMaxLease();

private:
    //Ranges of T1 i T2
    unsigned long T1Beg;
    unsigned long T1End;
    unsigned long T2End;
    unsigned long T2Beg;
    unsigned long PrefBeg;
    unsigned long PrefEnd;
    unsigned long ValidBeg;
    unsigned long ValidEnd;
    
    TContainer<SmartPtr<TStationRange> > RejedClnt;
    TContainer<SmartPtr<TStationRange> > AcceptClnt;
    TContainer<SmartPtr<TStationRange> > Pool;
    
    unsigned long ClassMaxLease;
};
#endif
