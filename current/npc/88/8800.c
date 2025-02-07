#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <skill.h>

#define MIN_SIZE 5	//开战的最少人数 5
#define MAX_SIZE 20	//单方的最大人数 20

inherit OFFICER;
inherit DBASE_F;

int WarId;
mapping mpInfo = ([
			//hp,mp,ap,dp,cp,pp,sp
	    "白起60" : ({1000000, 1000000,  700,  560,  650,  510,  300,}),
	    "白起80" : ({1200000, 1200000,  900,  720,  850,  670,  420,}),
	   "白起100" : ({1500000, 1500000, 1100,  880, 1050,  830,  540,}),
	   "白起120" : ({1900000, 1900000, 1300, 1040, 1250,  990,  660,}),
	   "白起150" : ({2500000, 2500000, 1600, 1280, 1550, 1230,  780,}),
	    "王屹60" : ({ 360000,  360000,  650,  510,  600,  460,  300,}),
	    "王屹80" : ({ 432000,  432000,  850,  670,  800,  620,  420,}),
	   "王屹100" : ({ 540000,  540000, 1050,  830, 1000,  770,  540,}),
	   "王屹120" : ({ 684000,  684000, 1350,  990, 1200,  940,  660,}),
	   "王屹150" : ({ 900000,  900000, 1550, 1230, 1500, 1180,  780,}),
	    "王陵60" : ({ 400000,  400000,  600,  510,  600,  460,  300,}),
	    "王陵80" : ({ 480000,  480000,  800,  670,  800,  620,  420,}),
	   "王陵100" : ({ 600000,  600000,  900,  830, 1000,  770,  540,}),
	   "王陵120" : ({ 760000,  760000, 1200,  990, 1200,  940,  660,}),
	   "王陵150" : ({1000000, 1000000, 1500, 1230, 1500, 1180,  780,}),
	  "司马错60" : ({ 400000,  400000,  600,  510,  600,  460,  300,}),
	  "司马错80" : ({ 480000,  480000,  800,  670,  800,  620,  420,}),
	 "司马错100" : ({ 600000,  600000,  900,  830, 1000,  770,  540,}),
	 "司马错120" : ({ 760000,  760000, 1200,  990, 1200,  940,  660,}),
	 "司马错150" : ({1000000, 1000000, 1500, 1230, 1500, 1180,  780,}),
	    "蒙骜60" : ({ 400000,  400000,  600,  510,  600,  460,  300,}),
	    "蒙骜80" : ({ 480000,  480000,  800,  670,  800,  620,  420,}),
	   "蒙骜100" : ({ 600000,  600000,  900,  830, 1000,  770,  540,}),
	   "蒙骜120" : ({ 760000,  760000, 1200,  990, 1200,  940,  660,}),
	   "蒙骜150" : ({1000000, 1000000, 1500, 1230, 1500, 1180,  780,}),
	    "廉颇60" : ({1000000, 1000000,  700,  560,  650,  510,  300,}),
	    "廉颇80" : ({1200000, 1200000,  900,  720,  850,  670,  420,}),
	   "廉颇100" : ({1500000, 1500000, 1100,  880, 1050,  830,  540,}),
	   "廉颇120" : ({1900000, 1900000, 1300, 1040, 1250,  990,  660,}),
	   "廉颇150" : ({2500000, 2500000, 1600, 1280, 1550, 1230,  780,}),
	    "赵括60" : ({ 360000,  360000,  650,  510,  600,  460,  300,}),
	    "赵括80" : ({ 432000,  432000,  850,  670,  800,  620,  420,}),
	   "赵括100" : ({ 540000,  540000, 1050,  830, 1000,  770,  540,}),
	   "赵括120" : ({ 684000,  684000, 1350,  990, 1200,  940,  660,}),
	   "赵括150" : ({ 900000,  900000, 1550, 1230, 1500, 1180,  780,}),
	    "乐乘60" : ({ 400000,  400000,  600,  510,  600,  460,  300,}),
	    "乐乘80" : ({ 480000,  480000,  800,  670,  800,  620,  420,}),
	   "乐乘100" : ({ 600000,  600000,  900,  830, 1000,  770,  540,}),
	   "乐乘120" : ({ 760000,  760000, 1200,  990, 1200,  940,  660,}),
	   "乐乘150" : ({1000000, 1000000, 1500, 1230, 1500, 1180,  780,}),
	    "冯亭60" : ({ 400000,  400000,  600,  510,  600,  460,  300,}),
	    "冯亭80" : ({ 480000,  480000,  800,  670,  800,  620,  420,}),
	   "冯亭100" : ({ 600000,  600000,  900,  830, 1000,  770,  540,}),
	   "冯亭120" : ({ 760000,  760000, 1200,  990, 1200,  940,  660,}),
	   "冯亭150" : ({1000000, 1000000, 1500, 1230, 1500, 1180,  780,}),
	    "郭开60" : ({ 400000,  400000,  600,  510,  600,  460,  300,}),
	    "郭开80" : ({ 480000,  480000,  800,  670,  800,  620,  420,}),
	   "郭开100" : ({ 600000,  600000,  900,  830, 1000,  770,  540,}),
	   "郭开120" : ({ 760000,  760000, 1200,  990, 1200,  940,  660,}),
	   "郭开150" : ({1000000, 1000000, 1500, 1230, 1500, 1180,  780,}),
]);

mapping mpNpc = ([
"秦国" : ([ 
	1 : ([ "file":"npc/88/1001", "nPos":({63,50}) ]),
	2 : ([ "file":"npc/88/1002", "nPos":({72,56}) ]),
	3 : ([ "file":"npc/88/1003", "nPos":({89,106}) ]),
	4 : ([ "file":"npc/88/1004", "nPos":({99,75}) ]),
	5 : ([ "file":"npc/88/1005", "nPos":({134,67}) ]),
	]),

"赵国" : ([ 
	1 : ([ "file":"npc/88/2001", "nPos":({185,142}) ]),
	2 : ([ "file":"npc/88/2002", "nPos":({168,133}) ]),
	3 : ([ "file":"npc/88/2003", "nPos":({166,86}) ]),
	4 : ([ "file":"npc/88/2004", "nPos":({156,117}) ]),
	5 : ([ "file":"npc/88/2005", "nPos":({115,127}) ]),
	]),
]);
int *nRankScore = ({ 100,250,625,1600,4000,10000,25000,62000,15300,382000,954000 });
// 函数：获取人物造型
int get_char_picid() { return 9609; }
void do_welcome( string arg );
void player_sign_up(object me,object who);
void team_sign_up(object me, object who);
int init_npc(object npc,int level);
void check_war_begin(int level,int wId);
void enter_changping(object who);
int check_valid_user(object who);
int count_sign_up(int level,int wId);
void refuse_changping(object who);
void abort_changping(object who);
int change_score(int score);
int kill_score(object who,object map);
void give_title(object me,object who,int iFlag);

// 函数：构造处理
void create()
{
	int i,size;
	string *nKey;
	mapping mpTmp;
        set_name("张果老");
        set_city_name("周国");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));  
        setup();

	if ( clonep(this_object()) )
		return ;
	WarId = "npc/88/8801"->get_2("warid");
	mpTmp = "npc/88/8801"->get_2("database");
	if ( !mapp(mpTmp) )
		return;
	nKey = keys(mpTmp);
	for(i=0,size=sizeof(nKey);i<size;i++)
	{
		set_2(nKey[i],mpTmp[nKey[i]]);	
	}
}

// 函数：对话处理
void do_look( object who )
{
	int level,z,wId;
	object me = this_object();
	int id=getoid(me);
	
	level = who->get_2("changping.level");
	if ( level )
	{
		z = __FILE__->get_2(sprintf("%d.%d.z",level,wId=who->get_2("changping.warid")));
		if ( !z )
			send_user(who,"%c%s",':',sprintf( "%s：\n    老仙我已经将你安排到了"HIR"%d级段的长平%d号战场"NOR"，所属阵营为"HIR"%s"NOR"，现在这个战场已经有"HIR"%d人"NOR"参加了报名。你还需要什么帮忙吗？\n"
				ESC"放弃报名\ntalk %x# welcome.5\n"
				ESC"换取战场奖励\ntalk %x# welcome.4\n"
				ESC"离开", get_name(),level,wId,who->get_2("changping.country"),__FILE__->count_sign_up(level,wId),id,id ) 
				);
		else
			send_user(who,"%c%s",':',sprintf( "%s：\n    老仙我已经将你安排到了"HIR"%d级段的长平%d号战场"NOR"，所属阵营为"HIR"%s"NOR"，现在这个战场已经有"HIR"%d人"NOR"参加了报名。你还需要什么帮忙吗？\n"
				ESC"进入长平之战\ntalk %x# welcome.3\n"
				ESC"换取战场奖励\ntalk %x# welcome.4\n"
				ESC"离开", get_name(),level,wId,who->get_2("changping.country"),__FILE__->count_sign_up(level,wId),id,id ) 
				);
//			send_user(who,"%c%s",':',sprintf( "%s：\n    我是张果老！没错，我的确很老，老得我自己都不记得自己有多老了。不过我记得的事情有很多，例如二十年前的长平之战，我是记得清清楚楚，怎么样？你想去亲身了解一下长平之战吗？我可以把你带到我的记忆里面去参加长平之战，但是我不能确保你会加入赵军方还是秦军方？现在要去吗？\n"
//				ESC"进入长平之战\ntalk %x# welcome.3\n"
//				ESC"换取战场奖励\ntalk %x# welcome.4\n"
//				ESC"离开", get_name(),id,id ) 
//				);
	}
	else
		send_user(who,"%c%s",':',sprintf( "%s：\n    我是张果老！没错，我的确很老，老得我自己都不记得自己有多老了。不过我记得的事情有很多，例如二十年前的长平之战，我是记得清清楚楚，怎么样？你想去亲身了解一下长平之战吗？我可以把你带到我的记忆里面去参加长平之战，但是我不能确保你会加入赵军方还是秦军方？现在要去吗？\n"
			ESC"个人参加长平之战\ntalk %x# welcome.1\n"
			ESC"队伍参加长平之战\ntalk %x# welcome.2\n"
			ESC"换取战场奖励\ntalk %x# welcome.4\n"
			ESC"离开", get_name(),id,id,id ) 
				);
	
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p,z,level,x,y,wId;
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() < 40 )
        	{
        		send_user(who,"%c%s",':',me->get_name()+"：\n    你现在年纪还小，不适合参加长平之战，等你40级以后再来吧！哈哈哈哈。\n"ESC"离开");
        		return;
        	}
        	player_sign_up(me,who);
        	break;
        case 2:
        	if ( who->get_level() < 40 )
        	{
        		send_user(who,"%c%s",':',me->get_name()+"：\n    你现在年纪还小，不适合参加长平之战，等你40级以后再来吧！哈哈哈哈。\n"ESC"离开");
        		return;
        	}
        	team_sign_up(me,who);
        	break;
        case 3:
		enter_changping(who);
        	break;
        case 4:		//领取奖励
        	x = who->get_save_2("changping.win");
        	y = who->get_save_2("changping.lose");
		send_user(who,"%c%s",':',sprintf( "%s：\n    你一共参与了"HIR"%d次"NOR"长平战役，其中胜利的战役一共有"HIR"%d场"NOR"。你现在一共有"HIR"%d点"NOR"战绩，你希望利用这些战绩换取什么奖励呢？\n"
			ESC"换取战场称谓\ntalk %x# welcome.7\n"
			ESC"取消", me->get_name(),x+y,x,who->get_save_2("changping.score"),getoid(me) ) 
				);        	
        	break;
        case 5:		//放弃报名
		send_user(who,"%c%s",':',sprintf( "%s：\n    你确定要放弃长平战场的报名吗？如果这样的话，要参加下一场战争的话，你就必须至少等待3分钟的时间才可以重新报名了。你确定这样做吗？\n"
			ESC"确定\ntalk %x# welcome.6\n"
			ESC"取消", me->get_name(),getoid(me) ) 
				);         	
        	break;
        case 6:
        	abort_changping(who);
        	break;
        case 7:
        	give_title(me,who,0);
        	break;
        case 8:
        	give_title(me,who,1);
        	break;
        }
}
//取得战场编号
int get_war_id(int level)
{
	int *nWar,wId,i,size;	
	if ( !mapp(get_2(sprintf("%d",level))) )
	{
		WarId++;
		wId = WarId;
	}
	else
	{
		nWar = 	keys(get_2(sprintf("%d",level)));
		for(i=0,size=sizeof(nWar);i<size;i++)
		{
			wId = to_int(nWar[i]);
			if ( sizeof(get_2(sprintf("%d.%d.秦国",level,wId))) >= MAX_SIZE && 
				sizeof(get_2(sprintf("%d.%d.赵国",level,wId))) >= MAX_SIZE )
				continue;
			break;
		}
		if ( i >= size )	//新开
		{
			WarId++;
			wId = WarId;
		}
	}	
	return wId;
}
//个人报名
void player_sign_up(object me,object who)
{
	int level,id,wId,sec;
	int *nMem1,*nMem2,*nMem;
	string cTmp;
	
	level = who->get_level();
	if ( level < 40 )
		return ;
	if ( level <= 60 )
		level = 60;
	else if ( level <= 80 )
		level = 80;
	else if ( level <= 100 )
		level = 100;
	else if ( level <= 120 )
		level = 120;
	else 
		level = 150;
	id = who->get_number();
	if ( check_valid_user(who) )
	{
		send_user(who,"%c%s",'!',"你已经报过名了！");
		return ;
	}
	if ( (sec=gone_time(who->get_save_2("changping.abort"))) < 180 )
	{
		send_user(who,"%c%s",'!',sprintf("要重新报名必须等待%d秒的时间。",180-sec));
		return ;
	}
	wId = get_war_id(level);
	nMem1 = get_2(sprintf("%d.%d.秦国",level,wId));	
	nMem2 = get_2(sprintf("%d.%d.赵国",level,wId));	
	if ( !arrayp(nMem1) )
		nMem1 = ({});
	if ( !arrayp(nMem2) )
		nMem2 = ({});

	if ( sizeof(nMem1) < sizeof(nMem2) )
	{
		nMem = nMem1;
		cTmp = "秦国";
	}
	else if ( sizeof(nMem1) > sizeof(nMem2) )
	{
		nMem = nMem2;
		cTmp = "赵国";
	}
	else if ( random(2) )
	{
		nMem = nMem1;
		cTmp = "秦国";
	}
	else
	{
		nMem = nMem2;
		cTmp = "赵国";
	}
	nMem += ({id});
	set_2(sprintf("%d.%d.%s",level,wId,cTmp),nMem);
	who->set_2("changping.level",level);
	who->set_2("changping.country",cTmp);
	who->set_2("changping.warid",wId);
	who->delete_2("changping.start");
//	send_user(who,"%c%s",';',"你报名加入长平之战！");
	send_user(who,"%c%s",':',sprintf("%s:\n    呵呵，老仙我已经将你安排到了"HIR"%d级段的长平%d号战场"NOR"，所属阵营为"HIR"%s"NOR"，现在这个战场已经有"HIR"%d人"NOR"参加了报名。\n"ESC"离开",me->get_name(),level,wId,cTmp,sizeof(nMem1+nMem2)+1));
	check_war_begin(level,wId);
}
//队伍报名
void team_sign_up(object me, object who)
{
	int i,size,*nMem1,*nMem2,*nMem,level,level1,level2,wId,*nWar,sec;
	object *nTeam,player;
	string cTmp;
	
	if( !who->is_leader() )
        {
                send_user(who,"%c%s",'!',"您不是队长。" );
                return ;
        }
	nTeam = who->get_team();
	nTeam -= ({0});
	size = sizeof(nTeam);
	if ( !size )
		return ;
	level = who->get_level();
	if ( level < 40 )
		return ;
	if ( level <= 60 )
	{
		level1 = 40;
		level2 = 60;
	}
	else if ( level <= 80 )
	{
		level1 = 61;
		level2 = 80;
	}
	else if ( level <= 100 )
	{
		level1 = 81;
		level2 = 100;
	}
	else if ( level <= 120 )
	{
		level1 = 101;
		level2 = 120;
	}
	else 
	{
		level1 = 121;
		level2 = 150;
	}
	for(i=0;i<size;i++)
	{
		player = nTeam[i];
		if ( !inside_screen_2(player,who) )
		{
//			send_user(who,"%c%s",':',me->get_name()+":\n    你的队伍有人不在现场，不能报名。\n"ESC"离开");	
			send_user(who,"%c%s",':',me->get_name()+":\n    你队伍中的"HIR+player->get_name()+NOR"不在现场，不能报名。\n"ESC"离开");	
			return ;
		}	
		if ( (level=player->get_level()) < 40 )
		{
//			send_user(who,"%c%s",':',me->get_name()+":\n    你队伍中有人现在年纪还小，不适合参加长平之战，等他40级以后再来吧！\n"ESC"离开");	
			send_user(who,"%c%s",':',me->get_name()+":\n    你队伍中的"HIR+player->get_name()+NOR"现在年纪还小，不适合参加长平之战，等他40级以后再来吧！\n"ESC"离开");	
			return ;
		}
		if ( level < level1 || level > level2 )
		{
//			send_user(who,"%c%s",':',me->get_name()+":\n    你队伍中有人的等级跟队伍的等级段不一致，不能报名！\n"ESC"离开");	
			send_user(who,"%c%s",':',me->get_name()+":\n    你队伍中的"HIR+player->get_name()+NOR"跟队伍的等级段不一致，请协调好之后再来我这里报名吧。\n"ESC"离开");	
			return ;
		}
		if ( check_valid_user(player) )
		{
//			send_user(who,"%c%s",':',me->get_name()+":\n    你队伍中有人已经报名了！\n"ESC"离开");	
			send_user(who,"%c%s",':',me->get_name()+":\n    你队伍中的"HIR+player->get_name()+NOR"已经报过名，请协调好之后再来我这里报名吧。\n"ESC"离开");	
			return ;
		}
		if ( (sec=gone_time(player->get_save_2("changping.abort"))) < 180 )
		{
			send_user(player,"%c%s",'!',sprintf("要重新报名必须等待%d秒的时间。",180-sec));
			send_user(who,"%c%s",':',me->get_name()+":\n    你队伍中的"HIR+player->get_name()+NOR"暂时不能进入战场，请协调好之后再来我这里报名吧。\n"ESC"离开");	
			return ;
		}
	}	
	level = level2;
	wId = get_war_id(level);
	nMem1 = get_2(sprintf("%d.%d.秦国",level,wId));	
	nMem2 = get_2(sprintf("%d.%d.赵国",level,wId));	
	if ( !arrayp(nMem1) )
		nMem1 = ({});
	if ( !arrayp(nMem2) )
		nMem2 = ({});
	if ( sizeof(nMem1) < sizeof(nMem2) )
	{
		nMem = nMem1;
		cTmp = "秦国";
	}
	else if ( sizeof(nMem1) > sizeof(nMem2) )
	{
		nMem = nMem2;
		cTmp = "赵国";
	}
	else if ( random(2) )
	{
		nMem = nMem1;
		cTmp = "秦国";
	}
	else
	{
		nMem = nMem2;
		cTmp = "赵国";
	}
	if ( sizeof(nMem) > (MAX_SIZE -sizeof(nTeam)) )
	{
		send_user(who,"%c%s",'!',"因为人数限制，你的队伍不能报名当前的战场，请等待下一场！");
		return ;
	}
	for(i=0;i<size;i++)
	{
		player = nTeam[i];
		nMem += ({ player->get_number() });		
		player->set_2("changping.level",level);
		player->set_2("changping.country",cTmp);
		player->set_2("changping.warid",wId);
		player->delete_2("changping.start");
		send_user(player,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    呵呵，老仙我已经将你安排到了"HIR"%d级段的长平%d号战场"NOR"，所属阵营为"HIR"%s"NOR"，现在这个战场已经有"HIR"%d人"NOR"参加了报名。\n"ESC"离开",me->get_name(),level,wId,cTmp,sizeof(nMem1+nMem2)+size));
	}
	set_2(sprintf("%d.%d.%s",level,wId,cTmp),nMem);	
//	send_user(who,"%c%s",';',"你的队伍报名加入长平之战！");
	check_war_begin(level,wId);
}
//检查是否开战
void check_war_begin(int level,int wId)
{
	int *nMem1,*nMem2,z,d=903,i;	
	object player,npc,map;
	mapping mpTmp,mpTmp1;
	
	if ( get_2(sprintf("%d.%d.z",level,wId)) )	//已经开战了
		return ;
	nMem1 = get_2(sprintf("%d.%d.秦国",level,wId));	
	nMem2 = get_2(sprintf("%d.%d.赵国",level,wId));	
	if ( sizeof(nMem1) < MIN_SIZE || sizeof(nMem2) < MIN_SIZE )
		return ;
	//开战
	if( ( z = find_map_flag(1000, 2999, 0) ) <= 0 ) 
		return ;
	init_virtual_map(z, d);		
        map = new( "/inh/std/changping" );
        map->set_client_id(d);
        map->set("warid",wId);
        map->set("warlevel",level);
        map->set("warbegin",time());
        set_map_object( map, map->set_id(z) ); 
        set_2(sprintf("%d.%d.z",level,wId),z);
	//生成NPC
	//小精怪
	npc = new("/npc/88/8801");
	npc->set_city_name("秦国");
	npc->add_to_scene(z,40,51,8);
	npc = new("/npc/88/8801");
	npc->set_city_name("赵国");
	npc->add_to_scene(z,201,149,4);
	//秦国
	mpTmp1 = mpNpc["秦国"];
	for(i=1;i<=5;i++)
	{
		mpTmp = mpTmp1[i];
		npc = new(mpTmp["file"]);
		npc->set_level(level);
		init_npc(npc,level);
	        npc->set_2( "nPos",mpTmp["nPos"]);
	        npc->set("warid",wId);
	        npc->set_name_color(HIR);
		npc->add_to_scene(z,mpTmp["nPos"][0],mpTmp["nPos"][1],3);
		map->set(sprintf("qin%d",i),npc);
	}
	//赵国
	mpTmp1 = mpNpc["赵国"];
	for(i=1;i<=5;i++)
	{
		mpTmp = mpTmp1[i];
		npc = new(mpTmp["file"]);
		npc->set_level(level);
		init_npc(npc,level);
	        npc->set_2( "nPos",mpTmp["nPos"]);
	        npc->set("warid",wId);
	        npc->set_name_color(HIB);
		npc->add_to_scene(z,mpTmp["nPos"][0],mpTmp["nPos"][1],3);		
		map->set(sprintf("zhao%d",i),npc);
	}
	
	
	//公告
	nMem1 += nMem2;
	for(i=0,z=sizeof(nMem1);i<z;i++)
	{
		player = find_char(sprintf("%d",nMem1[i]));
		if ( !objectp(player) )
			continue;
		send_user(player,"%c%c%w%s",':',3,0,sprintf("现在已经可以进入长平%d号战场了，你所归属的阵营为%s，是否马上进入？（超过60秒视为放弃进入）\n"
					ESC"进入战场\ndesc changping yes\n"
					ESC"放弃进入\ndesc changping no\n"
					,player->get_2("changping.warid"),player->get_2("changping.country"))
					);
		player->set_2("changping.start",time());
	}
	map->check_fighter(60);

}

//清除报名
void delete_sign_up(object who)
{
	int id,level,*nMem,wId;
	string cTmp;
	
	id = who->get_number();
	level = who->get_2("changping.level");	
	cTmp = who->get_2("changping.country");	
	wId = who->get_2("changping.warid");	
	if ( !level )
		return ;
	who->delete_2("changping");
	nMem = get_2(sprintf("%d.%d.%s",level,wId,cTmp));
	if ( !sizeof(nMem) )
		return ;
	if ( member_array(id,nMem) == -1 )
		return ;
	nMem -= ({ id });
	set_2(sprintf("%d.%d.%s",level,wId,cTmp),nMem);
}

int init_npc(object npc,int level)
{
	string cTmp;
	int *nTmp;
	
	npc->set_level(level);
	cTmp = sprintf("%s%d",npc->get_name(),level);
	if ( !arrayp(nTmp=mpInfo[cTmp]) )
	{
		log_file("changping.txt",sprintf("%s %s的错误等级%d\n",short_time(),npc->get_name(),level));
		return ;
	}
	npc->set_max_hp(nTmp[0]);
	npc->set_max_mp(nTmp[1]);
	npc->set_ap(nTmp[2]);
	npc->set_dp(nTmp[3]);
	npc->set_cp(nTmp[4]);
	npc->set_pp(nTmp[5]);
	npc->set_sp(nTmp[6]);
	return 1;
}
//发送最终报表
void send_war_report(object who,object map)
{
	int i,size,pos,score,win,lose,*nTmp,id;
	string cTmp,cCountry;
	mapping mpTmp,mpTmp1;
	
	mpTmp = map->get_2("player_info");
	if ( !mapp(mpTmp) )
		return ;
	cCountry = who->get_2("changping.country");
	if ( !stringp(cCountry) )
		return ;
	if ( who->get_2("changping.warid") != map->get("warid") )
		return ;
	id = who->get_number();
	if ( cCountry == map->get_2("win_country") )
		cTmp = "胜利|在诸位的英勇奋战之下，我军赢得了胜利。期待诸位今后摘取更多胜利之果。";
	else
		cTmp = "败北|尽管诸位英勇奋战，我军仍旧战败了。愿各位今后更加努力。";
	cTmp += "|" + map->get_2("win_country") + "|赵国|秦国";
	if ( cCountry == "秦国" )
	{
		win = 	map->get_2("qin_score");
		lose = 	map->get_2("zhao_score");
	}
	else
	{
		win = 	map->get_2("zhao_score");
		lose = 	map->get_2("qin_score");
	}
	if ( mapp(mpTmp[id]) )
		score = mpTmp[id]["score"]; 
	send_user(who,"%c%c%d%d%d%d%s", 0xA5,6,
		map->get_2("total_player"),win,lose,score,cTmp);
	nTmp = map->get_2("sort_player");
	size = sizeof(nTmp);
	if ( !size )
		return ;
	pos = member_array(id,nTmp);
	if ( size > 10 )
		size = 10;
	for(i=0;i<size;i++)
	{
		mpTmp1 = mpTmp[nTmp[i]];
		send_user(who,"%c%c%d%d%d%s", 0xA5,7,
			i+1,mpTmp1["kill"],mpTmp1["die"],
			mpTmp1["name"]+"|"+mpTmp1["country"]+"|"+mpTmp1["family"]);
	}
	if ( pos >= 10 )
	{
		mpTmp1 = mpTmp[id];
		send_user(who,"%c%c%d%d%d%s", 0xA5,7,
			pos+1,mpTmp1["kill"],mpTmp1["die"],
			mpTmp1["name"]+"|"+mpTmp1["country"]+"|"+mpTmp1["family"]);
	}
}
//活动结束
void game_over(object map,string cWin )
{
	int i,size,score,total,*nTmp=({});
	object who,*nPlayer;
	mapping mpTmp=([]);
	
	nPlayer = map->get_all_user();
	map->set("finish",1);
	map->set("win",cWin);
	map->game_over();
	delete_2(sprintf("%d.%d",map->get("warlevel"),map->get("warid")));
	//计算队伍得分
	map->add_2("totalscore.秦国",450);
	map->add_2("totalscore.赵国",450);
	for(i=0,size=sizeof(nPlayer);i<size;i++)
	{
		who = nPlayer[i];
		if ( !objectp(who) )
			continue;
		if ( who->get_2("changping.warid") != map->get("warid") )
			continue;
		if ( who->get_2("changping.country") == cWin )
			who->add_save_2("changping.win",1);
		else
			who->add_save_2("changping.lose",1);
		score = map->get_2(sprintf("score.%d",who->get_number()));
		score += 450;
		if ( score < 0 )
			score = 0;
		score = change_score(score);		//转换成战绩
		score += kill_score(who,map);
		who->add_save_2("changping.score",score);
		who->add_save_2("changping.totalscore",score);
		send_user(who,"%c%s",';',sprintf("你在长平之战中的战绩是%d点积分。",score));
log_file("changping.txt",sprintf("%s %d 总分%d 杀%d人 战绩1 %d 战绩2 %d 总战绩 %d \n",short_time(),who->get_number(),map->get_2(sprintf("score.%d",who->get_number()))+450,map->get_2(sprintf("kill.%d",who->get_number())),score-kill_score(who,map),kill_score(who,map),score));		
		//记录在场玩家的信息
		mpTmp[who->get_number()] = ([ 
			"name" : who->get_name(),
			"family" : who->get_fam_name(),
			"country" : who->get_2("changping.country"),
			"kill" : map->get_2(sprintf("kill.%d",who->get_number())),
			"die" : map->get_2(sprintf("killed.%d",who->get_number())),
			"score" : score,
			]);
		total ++;
		nTmp += ({who->get_number()});
	}
	map->set_2("player_info",mpTmp);
	map->set_2("win_country",cWin);
	map->set_2("total_player",total);
	map->set_2("attack_country","秦国");
	map->set_2("defend_country","赵国");
	map->set_2("qin_score",map->get_2("totalscore.秦国")*10000/2050);
	map->set_2("zhao_score",map->get_2("totalscore.赵国")*10000/2050);
	if ( sizeof(mpTmp) )
	{
		nTmp = sort_array(nTmp,"sort_cmp",map);
		map->set_2("sort_player",nTmp);
	}
	for(i=0,size=sizeof(nPlayer);i<size;i++)
	{
		who = nPlayer[i];
		if ( !objectp(who) )
			continue;
		if ( who->get_2("changping.warid") != map->get("warid") )
			continue;
		send_war_report(who,map);
	}
}

//杀死NPC的奖励和惩罚
void win_bonus( object me, object who )
{
	int iRank,iAdd,iSub,i,size,z;
	object *nPlayer,map,owner;
	string cCountry1,cCountry2,cTmp,cName,cWin;
	
	owner = who->get_owner();
	if ( owner && owner->is_user() )
		who = owner;
	iRank = me->get("rank");
	if ( iRank == 1 )
		iAdd = 500;
	else if ( iRank == 2 )
	{
		iAdd = 200;
		iSub = -80;
	}
	else if ( iRank >2 && iRank < 6 )
	{
		iAdd = 300;
		iSub = -120;
	}
	cCountry1 = who->get_2("changping.country");
	cCountry2 = me->get_city_name();
	cName = me->get_name();
	z = get_z(me);
	map = get_map_object(z);
	if ( !map )
		return ;
	nPlayer = map->get_all_user();
	if ( !stringp(cCountry1) )
		cCountry1 = "";
	if ( !stringp(cCountry2) )
		cCountry2 = "";
	nPlayer -= ({0});
	for(i=0,size=sizeof(nPlayer);i<size;i++)
	{
		who = nPlayer[i];
		if ( !objectp(who) )
			continue;
		if ( (cTmp=who->get_2("changping.country")) && cTmp == cCountry1 )	//同一方的
			map->add_2(sprintf("score.%d",who->get_number()),iAdd*who->get_online_rate()/100);
		else if ( (cTmp=who->get_2("changping.country")) && cTmp == cCountry2 )	//对方的
			map->add_2(sprintf("score.%d",who->get_number()),iSub);
	}
	//计算队伍得分
	map->add_2(sprintf("totalscore.%s",cCountry1),iAdd);
	map->add_2(sprintf("totalscore.%s",cCountry2),iSub);
	if ( cName == "白起" )
	{
		cWin = "赵国";
		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, HIR"秦军主将白起已经被赵军击败！长平之战以赵军胜利结束，1分钟后大家将会返回周国。" );
	}
	else if ( cName == "廉颇" )
	{
		cWin = "秦国";
		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, HIR"赵军主将廉颇已经被秦军击败！长平之战以秦军胜利结束，1分钟后大家将会返回周国。" );
	}
	else if ( cName == "王屹" )
		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, "秦军副将王屹已经被赵军击破！秦军形势一片危急！" );
	else if ( cName == "赵括" )
		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, "赵军副将赵括已经被秦军击破！赵军形势一片危急！" );
	else if ( cName == "司马错" )
		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, "秦军中军司马错部队已被赵军击退！秦军士气大受打击！" );
	else if ( cName == "冯亭" )
		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, "赵军中军冯亭部队已被秦军击退！赵军士气大受打击！" );
	else if ( cName == "王陵" )
		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, "秦军左先锋王陵部队已被赵军击退！秦军士气大受打击！" );
	else if ( cName == "乐乘" )
		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, "赵军左先锋乐乘部队已被秦军击退！赵军士气大受打击！" );
	else if ( cName == "蒙骜" )
		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, "秦军右先锋蒙骜部队已被赵军击退！秦军士气大受打击！" );
	else if ( cName == "郭开" )
		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, "赵军右先锋郭开部队已被秦军击退！赵军士气大受打击！" );
	if ( stringp(cWin) && !map->get("finish") )
	{
		game_over(map,cWin);
	}
}

int can_fight(object me, object who ) 
{ 
        object owner,map;
        string leader, id;

	if ( !who )
		return 0;
	if( who->is_die() )
	{
		me->set_enemy(0);
		return 0;
	}
	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() )
	{
		me->set_enemy(0);
		return 0;
	}
        if ( me->get_city_name() == who->get_2("changping.country") )
        	return 0;
        if ( me->get("warid") != who->get_2("changping.warid") )
        	return 0;        		
	map = get_map_object(get_z(me));
	if ( !map )
		return 0;
	if ( map->get("finish") )
		return 0;
	return 1;
}

int can_be_fighted(object me, object who ) 
{ 
	int i,size,p;
        object owner,map,*nPlayer,npc;
        string leader, id,cTmp,cTmp1;
        
	if ( !who )
		return 0;
	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() )
	{
		me->set_enemy(0);
		return 0;
	}
        if ( me->get_city_name() == who->get_2("changping.country") )
        	return 0;	
        if ( me->get("warid") != who->get_2("changping.warid") )
        	return 0;
	map = get_map_object(get_z(me));
	if ( !map )
		return ;
	if ( map->get("finish") )
		return 0;	
        if ( gone_time(me->get("relax")) > 15 )
        {
		if ( !map )
			return ;
		nPlayer = map->get_all_user();
        	nPlayer -= ({0});
        	if ( who->get_2("changping.country") == "秦国" )
        	{
        		cTmp = "秦军";
        		cTmp1 = "赵军";
		}        		
		else if ( who->get_2("changping.country") == "赵国" )
		{
        		cTmp1 = "秦军";
        		cTmp = "赵军";
        	}
		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, sprintf("%s已经展开对%s的%s将军的进攻。",cTmp,cTmp1,me->get_name()) );
		if ( me->get_name() == "白起" )
			npc = map->get("qin2");
		else if ( me->get_name() == "廉颇" )
			npc = map->get("zhao2");
		if ( npc )
		{
			p = get_valid_xy(get_z(me), get_x(me) + random(10) - 5, get_y(me) + random(10) - 5, IS_CHAR_BLOCK);
			if ( p )
			{
				npc->set_2("nPos",({p/1000,p%1000}));
				npc->add_to_scene( get_z(me), p / 1000, p % 1000,3,9413);
			}
		}	
        }
        me->set("relax",time());
        if ( me->get("lowhp") == 0 )
        {
        	if ( me->get_hp() < me->get_max_hp() /2 )
        	{
	        	if ( who->get_2("changping.country") == "秦国" )
	        	{
	        		cTmp = "秦军";
	        		cTmp1 = "赵军";
			}        		
			else if ( who->get_2("changping.country") == "赵国" )
			{
	        		cTmp1 = "秦军";
	        		cTmp = "赵军";
	        	}
			nPlayer = map->get_all_user();
        		nPlayer -= ({0});
        		me->set("lowhp",1);
        		send_user( nPlayer, "%c%c%d%s", 0x43, 10, 0, sprintf("由于%s的猛烈进攻，%s的%s将军陷于苦战之中，请%s勇士速往支援。",cTmp,cTmp1,me->get_name(),cTmp1) );
        	}	
        }
	return 1;
}

void before_destruct()
{
	"npc/88/8801"->set_2("database",get_dbase_2());
	"npc/88/8801"->set_2("warid",WarId);
	
}
//杀死对方玩家的奖励
void kill_player_bonus(object me,object who)
{
	int exp;
	object owner,map;
	if ( !who->is_user() )
		return ;
	owner = me->get_owner();
	if ( owner )
		me = who;
	write_user( who, HIR "您被%s杀死了！", me->get_name() );
	if ( !me->is_user() )
		return ;
	me->add_exp(exp=100+random(50));
	write_user( me, HIR "您杀死了%s！", who->get_name() );
	map = get_map_object(get_z(me));
	if (map && map->is_changping() )
	{
		if ( me->get_online_rate() == 100 )
		{
			map->add_2(sprintf("kill.%d",me->get_number()),1);
			me->add_save_2("changping.kill",1);
		}
		if ( who->get_online_rate() == 100 )
		{
			map->add_2(sprintf("killed.%d",who->get_number()),1);
			who->add_save_2("changping.killed",1);
		}
	}
}

void summon_guard(object me)
{
	int i,size,x,y,z,count,p,level,level1;
	object npc;

	x = get_x(me);y = get_y(me);z = get_z(me);
	level = me->get_level();
	for(i=0,size=8;i<size;i++)
	{
		if ( objectp(get(sprintf("guard%d",i))) )
			continue;
		p = get_valid_xy(z, x + random(10) - 5, y + random(10) - 5, IS_CHAR_BLOCK);
		if ( !p )
			continue;
		npc = new("npc/88/0001");	
		if ( !npc )
			break;
		level1 = level - (10+random(6));
		NPC_ENERGY_D->init_level( npc, level1 );  
		set(sprintf("guard%d",i),npc);
		if ( me->get_city_name() == "秦国" )
		{
			npc->set_char_picid(0650);
			npc->set_name(HIR+me->get_city_name()+"兵士");
		}
		else
		{
			npc->set_char_picid(0601);
			npc->set_name(HIB+me->get_city_name()+"兵士");
		}
		npc->add_to_scene( z, p / 1000, p % 1000);
		npc->set_owner(me);
		NPC_SLAVE_D->find_enemy(npc);    // 寻找敌人
		send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                        41311, 1, OVER_BODY, 41312, 1, OVER_BODY, 41313, 1, UNDER_FOOT, PF_ONCE );
	}
}
//进入长平战场
void enter_changping(object who)
{
	int level,wId,z,x,y,p;
	object map;
	
	level = who->get_2("changping.level");
	wId = who->get_2("changping.warid");
	if ( !level )
	{
		send_user(who,"%c%s",'!',"你已经放弃了进入长平战场，请重新报名！");
		return ;
	}
	z = get_2(sprintf("%d.%d.z",level,wId));
	if ( !z || !(map=get_map_object(z)) )
	{
		send_user(who,"%c%s",'!',"新的战场还没开启，请等待！");
		return ;
	}
	if ( who->get_2("changping.country") == "赵国" )
	{
		x = 196;
		y = 152;
	}
	else
	{
		x = 52;
		y = 48;
	}
	if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
        {
        	if ( who->get_leader() )	//踢出队伍
        		TEAM_D->remove_member( who->get_leader(), who );	
                x = p/1000, y = p % 1000;
                who->add_to_scene(z, x, y, 3);
		CHAR_CHAR_D->init_loop_perform(who);
                if ( who->get_2("changping.country") == "秦国" )
                {
                	send_user(who,"%c%s",';',sprintf("本战场已经开启了"HIR"%d分钟"NOR"，消灭敌军"HIR"主将廉颇"NOR"，胜利的荣耀将属于你们。",gone_time(map->get("warbegin"))/60+1));
			send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9005, 1, OVER_BODY, PF_LOOP );
		}
		else
		{
			send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9006, 1, OVER_BODY, PF_LOOP );
                	send_user(who,"%c%s",';',sprintf("本战场已经开启了"HIR"%d分钟"NOR"，消灭敌军"HIR"主将白起"NOR"，胜利的荣耀将属于你们。",gone_time(map->get("warbegin"))/60+1));
		}
        }	
	
}

//放弃进入战场
void refuse_changping(object who)
{
	int level,wId,z,x,y,p;
	
	level = who->get_2("changping.level");
	wId = who->get_2("changping.warid");
	if ( !level )
		return ;
	z = get_2(sprintf("%d.%d.z",level,wId));
	if ( z && z == get_z(who) )	//已经进入战场
		return ;
	delete_sign_up(who);
}
//检查是否已经报名
int check_valid_user(object who)
{
	int level,wId,*nMem;
	string cTmp;
	
	level = who->get_2("changping.level");
	if ( !level )
		return 0;
	wId = who->get_2("changping.warid");
	cTmp = who->get_2("changping.country");
	nMem = get_2(sprintf("%d.%d.%s",level,wId,cTmp));
	if ( !sizeof(nMem) )
		return 0;
	if ( member_array(who->get_number(),nMem) == -1 )
		return 0;
	return 1;		
}
//计算报名人数
int count_sign_up(int level,int wId)
{
	return sizeof(get_2(sprintf("%d.%d.秦国",level,wId))) + sizeof(get_2(sprintf("%d.%d.赵国",level,wId)));
}
//放弃
void abort_changping(object who)
{
	int level,wId,z,x,y,p;
	
	level = who->get_2("changping.level");
	wId = who->get_2("changping.warid");
	if ( !level )
		return ;
	z = get_2(sprintf("%d.%d.z",level,wId));
	if ( z && z == get_z(who) )	//已经进入战场
		return ;
	delete_sign_up(who);
	who->set_save_2("changping.abort",time());
	send_user(who,"%c%s",'!',"你放弃了参与长平之战！");
}
//按积分转换成战绩
int change_score(int score)
{
	if ( score < 91 )
		score = 1;
	else if ( score < 211 )
		score = 3;
	else if ( score < 331 )
		score = 6;
	else if ( score < 451 )
		score = 10;
	else if ( score < 651 )
		score = 15;
	else if ( score < 951 )
		score = 21;
	else if ( score < 1251 )
		score = 28;
	else if ( score < 1601 )
		score = 36;
	else 
		score = 45;

	return score;
}
//杀玩家的战绩兑换
int kill_score(object who,object map)
{
	int i;
	
	if ( !map )
		return 0;
	i = map->get_2(sprintf("kill.%d",who->get_number()));
	if ( i < 4 )
		i = 1;
	else if ( i < 9 )
		i = 3;
	else if ( i < 15 )
		i = 6;
	else if ( i < 22 )
		i = 10;
	else if ( i < 30 )
		i = 15;
	else if ( i < 39 )
		i = 21;
	else if ( i < 51 )
		i = 28;
	else
		i = 36;
	return i;
}
//给予战场称谓
void give_title(object me,object who,int iFlag)
{
	int iRank,iScore;
	string cTitle,cName,cTitle1,cName1;
	
	iRank = who->get_save_2("changping.rank");
	if ( iRank >= 11 )
	{
		send_user(who,"%c%s",'!',"现在没有更高级的称谓可以领取！");
		return ;
	}
	iScore = nRankScore[iRank];
	cTitle1 = "P"+sprintf("%03d",iRank);
	iRank++;
	cTitle = "P"+sprintf("%03d",iRank);
	cName = TITLE_D->get_titlename(cTitle);
	cName1 = TITLE_D->get_titlename(cTitle1);
	if ( cName == "" )
		return ;
	if ( iFlag == 0 )
	{
		if ( iRank == 1 )
			send_user(who,"%c%s",':',sprintf( "%s：\n    你之前没有领取过任何的战场称谓，领取第一个战场称谓"HIR"“战国新兵”"NOR"需要"HIR" 100点战绩 "NOR"，你确定要换取这个称谓吗？\n"
				ESC"同意\ntalk %x# welcome.8\n"
				ESC"我再考虑考虑", me->get_name(),getoid(me) ) 
					);        	
		else 
			send_user(who,"%c%s",':',sprintf( "%s：\n    你已经拥有了"HIR"%s"NOR"的头衔，继续进阶的话可领取新的战场称谓"HIR"%s"NOR"，但是必须消耗"HIR" %d点战绩 "NOR"，你确定要换取这个称谓吗？\n"
				ESC"同意\ntalk %x# welcome.8\n"
				ESC"我再考虑考虑", me->get_name(),cName1,cName,iScore,getoid(me) ) 
					); 
		return ;
	}
	if ( who->get_save_2("changping.score") < iScore )
	{
		send_user(who,"%c%s",':',sprintf( "%s：\n    看来你的战绩还是不够啊，多多在战场磨炼磨炼，得到更多的战绩之后再找本仙吧。\n"
				ESC"离开", me->get_name() ) 
					); 
		return ;
	}
	who->add_save_2("changping.score",-iScore) ;
	who->set_save_2("changping.rank",iRank) ;
	who->delete_title(cTitle1);
	who->add_title(cTitle);
	send_user(who,"%c%s",'!',"你得到了新的称谓"+HIR+cName);
}

void leave_changping(object who)
{
	int p;
	if ( !who->get_2("changping") )
		return ;
	who->delete_2("changping");
	if( p = get_valid_xy(80, 243, 156, IS_CHAR_BLOCK) )
        {
        	CHAR_CHAR_D->init_loop_perform(who);
                who->add_to_scene(80, p/1000, p % 1000);
        }
        else
        {
        	CHAR_CHAR_D->init_loop_perform(who);
        	MAP_D->add_to_void(who); 
        }	
	
	
}