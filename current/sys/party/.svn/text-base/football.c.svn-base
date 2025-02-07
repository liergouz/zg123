/*****四色足球****/

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>
#include <action.h>

// 函数：生成二进制码
void SAVE_BINARY() { }
// 函数：构造处理
void create()
{
	call_out("check_time",1);
}

void check_time()
{
	int iTime,rate,level,z,p,x,y;
	int i,*nScene,size;
	mixed *mixTime;
	object robber;
	
	remove_call_out("check_time");
	iTime = time();
	
	mixTime = localtime(iTime);

	if ( mixTime[TIME_WDAY] < 5 && mixTime[TIME_WDAY] != 0 )
	{
		call_out("check_time",3600*12);
		return ;
	}
	if ( mixTime[TIME_HOUR] < 17  )
	{
		call_out("check_time",60*(60-mixTime[TIME_MIN]));
		return ;
	}
	if ( mixTime[TIME_MIN] < 55  )
	{
		call_out("check_time",60*(55-mixTime[TIME_MIN]));
		return ;
	}
	CHAT_D->sys_channel(0,sprintf(HIY"听说"HIR"%d分钟后"HIY"可恶的怪物们又开始进行破坏良田的足球比赛了！作为战国勇士，应该在第一时间内将他们的足球抢过来，抢来的足球都可找"HIR"兑换天使"HIY"换取报酬！",60-mixTime[TIME_MIN]));
	call_out("check_time2",60*(60-mixTime[TIME_MIN]));
	call_out("check_time",3600*54);	
}

void check_time2()
{
	CHAT_D->sys_channel(0,HIY"怪物的足球赛开始了！请勇士们各就各位，将他们的足球抢过来，使这些良田杀手不再嚣张！"HIR"足球可找兑换天使换取出击的报酬！");
}