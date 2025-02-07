
#include <ansi.h>
#include <task.h>
#include <time.h>
#include <city.h>

inherit DBASE_F;
inherit SAVE_F;

#define _TEST_WS

#define ENTER_WUSHUANG(x)	x->add_to_scene(701,121,141);
#define GET_TIME	get_party_time()
#define START_ATT_HOUR	19
#define START_ATT_MIN	30
#define FINISH_ATT_HOUR	21
#define FINISH_ATT_MIN	0

int iFlag;		//0 为关闭
int iWarStatus;
void org_title(string cName,int flag);
int check_war_time();
string get_occupy_org()	;

// 函数：生成二进制码
void SAVE_BINARY() { }

string get_save_file()	{ return "data/wushuang"SAVE_EXTENSION;}

void create()
{
	object npc;
	
	restore();
	call_out("check_time",3);

}

int check_join_attack(object me, object who)
{
	int date;
	mixed *mxTime;
	
	if ( iFlag == 1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    这个活动还没开启！\n"ESC"离开",me->get_name()));
		return 0;	
	}
	if ( who->get_org_position() != ORG_MASTER )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    只有帮主才有资格申请攻占无双城！\n"ESC"离开",me->get_name()));
		return 0;	
	}
	mxTime = localtime(GET_TIME);
	date = mxTime[TIME_YEAR]*10000+ (mxTime[TIME_MON]+1)*100 + mxTime[TIME_MDAY];
	if ( get_save_2("join_org."+who->get_org_name()+".date") >= date )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你的帮派已经申请参加攻城了，不能重复报名！\n"ESC"离开",me->get_name()));
		return 0;	
	}
	if ( who->get_cash() < 1000000 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你所携带的金钱不足以支付攻城费用！\n"ESC"离开",me->get_name()));
		return 0;	
	}	
		
	return 1;	
}
void query_join_attack(object me, object who)
{
	
	if ( check_join_attack(me,who) != 1 )
		return ;
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    无双城乃是实力和地位的象征！你想攻占无双城，得到这至高无上的荣耀，必须先交纳1000000金的申请费用！\n"ESC"申请攻城\ntalk %x# welcome.75\n"ESC"离开",me->get_name(),getoid(me)));
	
}

void join_attack(object me, object who)
{
	int date;
	string *nTmp;
	mixed *mxTime;
	
	if ( check_join_attack(me,who) != 1 )
		return ;
	who->add_cash(-1000000);
	mxTime = localtime(GET_TIME+200);
	date = mxTime[TIME_YEAR]*10000+ (mxTime[TIME_MON]+1)*100 + mxTime[TIME_MDAY];
	nTmp = get_save_2(sprintf("attack_list.%d.orgs",date));
	if ( !arrayp(nTmp) )
		nTmp = ({ who->get_org_name() });
	else
		nTmp += ({ who->get_org_name() });
	set_save_2(sprintf("attack_list.%d.orgs",date),nTmp);
	set_save_2("join_org."+who->get_org_name()+".date",date);
	save();
	//发邮件给帮众
	"sys/sys/manager"->org_mail(0,who->get_org_name(),sprintf("    本帮将于%d月%d日%02d：%02d—%02d：%02d攻打无双城，请各位成员届时做好攻城准备。",mxTime[TIME_MON]+1,mxTime[TIME_MDAY],START_ATT_HOUR,START_ATT_MIN,FINISH_ATT_HOUR,FINISH_ATT_MIN));
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你已经成功申请攻打无双城，攻城时间为晚上19.30-21.00，你也可以前去周国无无双城守卫（270，187）那里查询。\n"ESC"离开",me->get_name()));
	
}
//进入无双城
void trans_into_wushuang(object me,object who)
{
	int p,x,y;
	
	if ( iFlag == 1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    这个活动还没开启！\n"ESC"离开",me->get_name()));
		return 0;	
	}
	if( !(p = get_jumpin(888, 1)) )
		return ;
	who->add_to_scene(888,p/1000,p%1000);
                                        
}
//攻城列表
void attack_list(object me,object who)
{
	int i,j,size,date;
	mixed *mxTime;
	string cTmp;
	string *nTmp;
	
	cTmp = "";
	if ( iFlag == 1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    这个活动还没开启！\n"ESC"离开",me->get_name()));
		return 0;	
	}
	for(j=0;j<3;j++)
	{
		mxTime = localtime(GET_TIME + 3600*24*j);
		date = mxTime[TIME_YEAR]*10000+ (mxTime[TIME_MON]+1)*100 + mxTime[TIME_MDAY];	
		nTmp = get_save_2(sprintf("attack_list.%d.orgs",date));
		if ( !arrayp(nTmp) || !(size=sizeof(nTmp)) )
			continue;
		cTmp += sprintf("    %2d月%2d日: ",mxTime[TIME_MON]+1,mxTime[TIME_MDAY]);
		for(i=0;i<size;i++)
		{
			cTmp += nTmp[i] + "帮会、";	
		}
		cTmp += "\n";
	}
	if ( sizeof(cTmp) == 0 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    目前还没有申请攻城的帮派。\n"ESC"离开",me->get_name()));
		return ;	
	}
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    近期攻城帮会有:\n%s\n"ESC"离开",me->get_name(),cTmp));
}
//占领城市
void occupy_city(object me, object who)
{
	int date,date1,flag,i,size;
	string org_name,old_org;
	mixed *mxTime;
	object map,*nPlayer,oPlayer;
	
	if ( iFlag == 1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    这个活动还没开启！\n"ESC"离开",me->get_name()));
		return ;	
	}
	if ( gone_time(me->get("occupy_time")) < 5 )	//限制申请的间隔
		return ;
	me->set("occupy_time",GET_TIME);
	map = get_map_object(get_z(me));
	if ( !map || !map->is_wushuang() )
		return ;
	if ( who->get_org_position() != ORG_MASTER )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    只有帮主才可申请占领无双城！\n"ESC"离开",me->get_name()));
		return ;	
	}
	if ( get_save_2("occupy_org") == (org_name=who->get_org_name()) )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你的帮派已经占领无双城，无须再次占领！\n"ESC"离开",me->get_name()));
		return ;	
	}	
	mxTime = localtime(GET_TIME);
	date = mxTime[TIME_YEAR]*10000+ (mxTime[TIME_MON]+1)*100 + mxTime[TIME_MDAY];
	if ( !get_save_2("old_occupy_org") || get_save_2("old_occupy_org") != org_name )
	{
		if ( (date1=get_save_2("join_org."+org_name+".date")) < date )
		{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你的帮派没有申请攻城，不能占领！\n"ESC"离开",me->get_name()));
			return ;	
		}
		if ( date1 > date )
		{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你的帮派没有申请今日攻打无双城！\n"ESC"离开",me->get_name()));
			return ;	
		}
	}
	if ( check_war_time() != 1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    现在是非攻城时间，申请无效！\n"ESC"离开",me->get_name()));
		return ;	
	}
	nPlayer = map->get_all_user();
	size = sizeof(nPlayer);
	if ( !size )
		return ;
	for(i=0;i<size;i++)
	{
		oPlayer = nPlayer[i];
		if ( oPlayer && oPlayer->get_org_name() == org_name )
			continue;
		if ( oPlayer->is_die() )
			continue;
		flag = -1;			
		break;	
	}
	if ( flag == -1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    无双宫内还有其他帮会玩家，申请不予批准！\n"ESC"离开",me->get_name()));
		return ;	
	}
	old_org = get_save_2("occupy_org");
	set_save_2("occupy_org",org_name);	
	set_save_2("occupy_time",GET_TIME);
	log_file("wushuang.txt",sprintf("%s %s(%d) %s 占领无双城\n",
		short_time(GET_TIME),who->get_name(),who->get_number(),org_name));
	save();
	org_title(org_name,1);
	org_title(old_org,0);
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    贵帮已成功占领无双城，您现在是“无双城主”！\n"ESC"离开",me->get_name()));
	CHAT_D->sys_channel(0,sprintf(HIY"%s"NOR"率领的"HIY"%s"NOR"帮会已成功占领无双城！",who->get_name(),org_name));
	CHAT_D->sys_channel(0,sprintf(HIY"%s"NOR"率领的"HIY"%s"NOR"帮会已成功占领无双城！",who->get_name(),org_name));
	CHAT_D->sys_channel(0,sprintf(HIY"%s"NOR"率领的"HIY"%s"NOR"帮会已成功占领无双城！",who->get_name(),org_name));
}

//检查称谓
void check_org_title(object who)
{
	if ( who->get_org_name() == get_save_2("occupy_org") )	
	{
		if ( who->get_org_position() == ORG_MASTER )
		{
			if ( !who->have_title("Z888") )
				who->add_title("Z888");
			if ( who->have_title("Z889") )
				who->delete_title("Z889");
		}
		else
		{
			if ( who->have_title("Z888") )
				who->delete_title("Z888");
			if ( !who->have_title("Z889") )
				who->add_title("Z889");
		}	
	}
	else
	{
		if ( who->have_title("Z888") )
			who->delete_title("Z888");
		if ( who->have_title("Z889") )
			who->delete_title("Z889");
	}
}
//处理无双称谓
void org_title(string cName,int flag)
{
	int i,size;
	object orgnpc,who;
	string cTmp,*nName;

	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", cName ) );
	if (!objectp(orgnpc))
		return ;
	size = orgnpc->sizeof_member_dbase();
	nName = orgnpc->get_all_member();
	for(i=0;i<size;i++)
	{
		who = find_char(nName[i]);
		if ( !who )
			continue;
		check_org_title(who);
		if ( flag )
		{
			if ( who->get_org_position() == ORG_MASTER )
				who->show_title("Z888");
			else
				who->show_title("Z889");
		}
	}	
}

void check_time()
{
	int iStart,iStart1,iFinish,date,i,size;
	mixed *mxTime;
	string *nTmp,org_name,master_name,cTmp;
	object orgnpc;
	
	remove_call_out("check_time");
	if ( iFlag == 1 )
	{
		call_out("check_time",3600*24);	
		return ;
	}
	mxTime = localtime(GET_TIME);
	date = mxTime[TIME_YEAR]*10000+ (mxTime[TIME_MON]+1)*100 + mxTime[TIME_MDAY];
	iStart = mktime(mxTime[TIME_YEAR],mxTime[TIME_MON]+1,mxTime[TIME_MDAY],START_ATT_HOUR,START_ATT_MIN,0);
	iFinish = mktime(mxTime[TIME_YEAR],mxTime[TIME_MON]+1,mxTime[TIME_MDAY],FINISH_ATT_HOUR,FINISH_ATT_MIN,0);
	if ( GET_TIME < iStart )	//攻城前
	{
		call_out("check_time",iStart-GET_TIME);	
		if ( iWarStatus )
		{
			iWarStatus = 0;
			set_save_2("old_occupy_org",get_save_2("occupy_org"));
			save();	
		}
		return ;
	}
	if ( GET_TIME < iFinish )	//攻城期间
	{
		call_out("check_time",iFinish-GET_TIME);
		if ( !iWarStatus )
			iWarStatus = 1;
	}
	else	//攻城后
	{
		mxTime = localtime(iStart+3600*24);	//下次攻城时间
		iStart1 = mktime(mxTime[TIME_YEAR],mxTime[TIME_MON]+1,mxTime[TIME_MDAY],START_ATT_HOUR,START_ATT_MIN,0);
		call_out("check_time",iStart1-GET_TIME);
		if ( iWarStatus && iWarStatus < 5 )
			iWarStatus = 5;
	}
	if ( iWarStatus == 1 )
	{
		iWarStatus = 2;
		nTmp = get_save_2(sprintf("attack_list.%d.orgs",date));
		if ( check_war_time() == 1 )
		{
			size = sizeof(nTmp);
			for(i=0;i<size;i++)
			{
				"sys/sys/manager"->org_mail(0,nTmp[i],HIY"    本帮即将攻打无双城，请各位帮众速来助阵！");
			}
			CHAT_D->sys_channel(0,"无双城争夺战开始了！");
		}
	}
	else if ( iWarStatus == 5 )	//清除旧的数据
	{
		iWarStatus = 0;
		set_save_2("old_occupy_org",get_save_2("occupy_org"));
		nTmp = get_save_2(sprintf("attack_list.%d.orgs",date));
		size = sizeof(nTmp);
		for(i=0;i<size;i++)
		{
			delete_save_2("join_org."+nTmp[i]);
		}
		delete_save_2(sprintf("attack_list.%d",date));
		if ( org_name=get_occupy_org() )
		{
			orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", org_name ) );
			if (objectp(orgnpc))
			{	
				master_name = orgnpc->get_master_name();
				cTmp = sprintf(HIR"无双城争夺战正式结束，"HIG"%s"HIR"帮在"HIG"%s"HIR"英明的领导下成功占领了无双城，大家对其表示祝贺！！！",org_name,master_name);
				for(i=0;i<4;i++)
				{
					CHAT_D->sys_channel(0,cTmp);
					send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
				}
			}
		}
	}
	save();
}
//是否可以进入无双宫
int can_enter_palace(object who,object map)
{
	string org_name;

	org_name = get_save_2("occupy_org");
	if ( sizeof(org_name) &&  org_name == who->get_org_name() )	//占领的帮派
		return 1;
	//攻打时间内才能进去
	if ( check_war_time() != 1 )
		return 0;
	return 1;
}
//判断是否攻城时间
int check_war_time()
{
	mixed *mxTime;	
	
	if ( iFlag == 1 )
		return 0;	
	mxTime = localtime(GET_TIME);
	if ( mxTime[TIME_HOUR] < START_ATT_HOUR 
		|| (mxTime[TIME_HOUR] == START_ATT_HOUR && mxTime[TIME_MIN] < START_ATT_MIN)
		|| (mxTime[TIME_HOUR] > FINISH_ATT_HOUR ) 	
		|| (mxTime[TIME_HOUR] == FINISH_ATT_HOUR && mxTime[TIME_MIN] >= FINISH_ATT_MIN) )
		return 0;
	return 1;
}
//查询占领的帮派
string get_occupy_org()	
{
	string org_name;
	
	org_name = get_save_2("occupy_org");
	return org_name?org_name:"";
}

//设置活动状态	0 关闭 1 开启
int set_flag(int i)
{
	iFlag = i;
	save();
	check_time();
	return iFlag;	
}
//获取状态
void get_status(object who)
{
	if ( iFlag == 0 )
		tell_user(who,"无双攻城战当前的状态是：关闭");	
	if ( iFlag == 1 )
	{
		tell_user(who,"无双攻城战当前的状态是：开启");	
		tell_user(who,sprintf("活动的时间是：%02d点%02d分－%02d点%02d分",START_ATT_HOUR,START_ATT_MIN,FINISH_ATT_HOUR,FINISH_ATT_MIN));	
	}
	
}
//设置游戏时间
void set_wushuang_time(object who ,string tmp)
{
	int year,mon,day,hour,min,sec;		
	
	if ( sscanf(tmp,"%d-%d-%d %d:%d:%d",year,mon,day,hour,min,sec) != 6 )
	{
		send_user(who,"%c%s",'!',"错误的时间格式");
		return ;
	}
	tell_user(who,"游戏的活动时间设置为：%s",short_time(set_party_time(year,mon,day,hour,min,sec)));
	check_time();
	if ( iFlag == 0 )
		tell_user(who,"无双攻城战当前的状态是：关闭");
	else
		tell_user(who,"无双攻城战当前的状态是：开启");
}