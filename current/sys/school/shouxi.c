//首席大弟子控制模块

#include <ansi.h>
#include <time.h>
#include <npc.h>

#define DEBUG(arg)	if(find_char("21")) tell_user(find_char("21"),arg);
#define FILE_ENERGY "sys/user/energy"
#define FILE_MINGREN "sys/party/mingren"

inherit DBASE_F;
inherit SAVE_F;

static string *SchoolName = ({"桃花源","禁卫军","蜀山","昆仑山","茅山","云梦泽","唐门",});
static mapping mpPic = (["禁卫军":40000,"茅山":80000,"云梦泽":70000,"桃花源":20100,"蜀山":30100,"昆仑山":60100,"唐门":50100]);
static mapping mpPos = (["禁卫军":({80,172,77,8}),"茅山":({269,261,173,4}),"云梦泽":({165,110,23,3}),"桃花源":({289,84,73,4}),"蜀山":({273,203,152,3}),"昆仑山":({54,124,128,3}),"唐门":({324,94,118,3})]);
static string cTmp;
static int iGen;
static string *nDrugs = ({ 
		"item/91/9125","item/91/9150","item/91/9160","item/91/9161","item/91/9162",
		"item/91/9163","item/91/9164","item/91/9165",	
	});
int iTimes;	//竞选的次数

void open_vote();
void start_vote();
void generate_shouxi();

// 函数：生成二进制码
void SAVE_BINARY() { }

string get_save_file()	{ return "data/shouxi"SAVE_EXTENSION;}

void create()
{
	restore();
	call_out("check_time",3);
}

int check_price(object who)
{
	int i;
	if ( (i=who->get_level()) < 30 )
		i = 50000;
	else 
		i = i * i * 10 + 50000;
	return i;	
}
void check_time()
{
	int i;
	mixed *mixTime;

	
	remove_call_out("check_time");
	mixTime = localtime(get_party_time());
	if ( mixTime[TIME_WDAY] == 0 )
		call_out("check_time",60*(60-mixTime[TIME_MIN]));
	else
		call_out("check_time",3600*12);	
		
	i = (get_party_time() - 4 * 24*3600+8*3600) / (7*24*3600);
	if ( iTimes != i )	//生成新一周的首席弟子
	{
		iTimes = i;
		open_vote();
		
		start_vote();
		generate_shouxi();
		iGen = 1;
		FILE_MINGREN->check_time();
		save();
	}
	if ( iGen != 1 )	//没生成的就生成
	{
		generate_shouxi();
		iGen = 1;
	}
	

}

void do_look( object me,object who )
{
	int id = getoid(me),picid;
	string fam_name,name;
	
	fam_name=me->get("fam_name");
	if ( (picid=me->get_armor_code()) == 0 )
		picid = mpPic[fam_name];
	name = me->get_real_name() ? me->get_real_name() : me->get_name();
	if ( fam_name != who->get_fam_name() )
	{
		send_user( who, "%c%c%w%s", ':',3,picid,name+":\n    你来本门有何贵干？若是来惹是生非，作为本门首席大弟子的我定不会轻饶你！\n"+
			ESC"离开");
		return ;	
	}
	send_user( who, "%c%c%w%s", ':',3,picid,name +":\n    我是本门首席大弟子，本门弟子都以能当选上首席大弟子为荣，你想获得这份荣耀吗？那你还须多加努力！\n"+
		sprintf(ESC"竞选首席大弟子\ntalk %x# elect\n",id) +
		sprintf(ESC"我要投票\ntalk %x# list\n",id) +
		sprintf(ESC"领取门派称谓\ntalk %x# hornor.0\n",id) +
		sprintf(ESC"兑换宝物\ntalk %x# exchange.0\n",id) +
		ESC"离开");	
	
}

void join_elect( object me,object who )
{
	int picid;
	string fam_name,name;
	if ( (fam_name=me->get("fam_name")) != who->get_fam_name() )
		return ;
	if ( (picid=me->get_armor_code()) == 0 )
		picid = mpPic[fam_name];
	name = me->get_real_name()?me->get_real_name():me->get_name();
	send_user( who, "%c%c%w%s", ':',3,picid,name+sprintf(":\n    你要想竞选首席大弟子，除非你先打败我！此外你还须交纳%d金的竞选费。倘若你没有点实力，我劝你还是尽早离开！\n",check_price(who))+
		sprintf(ESC"确定\ntalk %x# fight\n",getoid(me)) +
		ESC"离开");	
	
}

void do_fight( object me,object who )
{
	int iCash,level,z,d,family,x,y,p,pic,picid,price;
	string cityname,fam_name,name;
	object npc,map;

	if ( (fam_name=me->get("fam_name")) != who->get_fam_name() )
		return ;
	if ( (picid=me->get_armor_code()) == 0 )
		picid = mpPic[fam_name];
	name = me->get_real_name()?me->get_real_name():me->get_name();
	if ( sizeof(get_save_2(sprintf("elect.%s",who->get_fam_name()))) >= 20 )
	{
		send_user( who, "%c%c%w%s", ':',3,picid,name+":\n    这位师弟，本周竞选名额已满，你还是等待参与下周首席大弟子的竞选吧！\n"+
			ESC"离开");		
		return ;
	}
	if ( mapp(get_save_2(sprintf("elect.%s.%d",who->get_fam_name(),who->get_number()))) )
	{
		send_user( who, "%c%c%w%s", ':',3,picid,name+":\n    你已经参加竞选了！\n"+
			ESC"离开");		
		return ;
	}	
	price = check_price(who);		
	if( ( z = find_map_flag(1000, 2999, 0) ) <= 0 ) return ;
	if ( (iCash=who->get_cash()) < price )
	{
		send_user(who,"%c%s",'!',"您的竞选费不够！");
		return ;	
	}
	switch(who->get_fam_name())
	{
	case "桃花源": 	
	        family = 10; 
	        d = 891;
	        cityname = "桃花岛";
	        break;
	case "蜀山": 	
	        family = 20; 
	        d = 892;
	        cityname = "蜀岭峰";			        
	        break;
	case "禁卫军": 	
	        family = 30; 
	        d = 893;
	        cityname = "禁卫军营地";			        				        
	        break;
	case "唐门": 	
	        family = 40; 
	        d = 894;
	        cityname = "唐门密室";			        
	        break;
	case "茅山": 	
	        family = 50; 
	        d = 895;
	        cityname = "鬼门府";			        
	        break;
	case "昆仑山": 	
	        family = 60; 
	        d = 896;
	        cityname = "昆仑仙境";			        
	        break;
	default: 	
	        family = 70; 
	        d = 897;
	        cityname = "死亡沼泽";			        
	        break;
	}
	level = who->get_level()+5;
	npc = new("npc/school/00011");
	if ( !npc )
		return ;

	init_virtual_map(z, d);	
        map = new( NEWBIE );
        map->set_client_id(d);
        map->set_owner(who);
        set_map_object( map, map->set_id(z) );       
        map->set_name(cityname);    
        p = get_jumpin(z, 1);		
	NPC_ENERGY_2_D->init_family(npc, family, level, -1);
	npc->add_dp(npc->get_dp()/10);
	npc->add_max_hp(npc->get_max_hp()*4);
	npc->add_pp(npc->get_pp()/10);
	npc->add_mp(npc->get_mp()/2);
	npc->add_ap(-npc->get_ap()/10);
	
	
	npc->set_fam_name(who->get_fam_name());
	npc->set_char_type(FIGHTER_TYPE_2);
	npc->set_name(me->get_name());
	npc->set_real_name(me->get_real_name());
//	npc->set_char_picid(mpPic[who->get_fam_name()]);
	who->set_2("shouxi.x", get_x(who));
	who->set_2("shouxi.y", get_y(who));
	who->set_2("shouxi.z", get_z(who));
	x = p/1000, y = p % 1000;
	npc->set("user", who->get_number());
	if( stringp(get_save_2(sprintf("winners.%s.name",who->get_fam_name()))) )
	{
		if (pic=get_save_2(sprintf("winners.%s.armorcode",who->get_fam_name())))
			npc->set_armor_code(pic);
		else
			npc->set_armor_code(mpPic[who->get_fam_name()]);
	}
	else
	{
		npc->set_armor_code(mpPic[who->get_fam_name()]);
	}	
	npc->add_to_scene(z, x, y, 3);
	if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
        {
                x = p/1000, y = p % 1000;
                who->add_to_scene(z, x, y, 3);
             
        }		
	who->add_cash(-price);
}
//加入竞选
void add_elect(object who)
{
	string fam_name;
	
	fam_name = who->get_fam_name();
	set_save_2(sprintf("elect.%s.%d.name",fam_name,who->get_number()),who->get_name());
	set_save_2(sprintf("elect.%s.%d.armorcode",fam_name,who->get_number()),who->get_armor_code());
	set_save_2(sprintf("elect.%s.%d.level",fam_name,who->get_number()),who->get_level());
	save();
	log_file("schoolvote.txt",sprintf("%s %s %d %s 加入竞选\n",short_time(),fam_name,who->get_number(),who->get_name()));
}
//列表竞选名单
void do_list(object me,object who)
{
	int i,size,id;
	string fam_name,*key;
	mapping mpTmp;
	
	if ( me->get("fam_name") != who->get_fam_name() )
		return ;
	fam_name = me->get("fam_name");
	mpTmp = get_save_2("elect."+fam_name);
	if ( !mapp(mpTmp) )
	{
		send_user(who,"%c%s",'!',"现在没有人参加竞选");
		return ;
	}
	key = keys(mpTmp);
	id = getoid(me);
	for(i=0,size=sizeof(key);i<size;i++)
	{
//tell_user(who,"%d %d %d %s",to_int(key[i]),id,mpTmp[key[i]]["point"],mpTmp[key[i]]["name"]);
		send_user(who,"%c%c%d%d%w%w%s",0xA0,1,to_int(key[i]),id,mpTmp[key[i]]["level"],mpTmp[key[i]]["point"],mpTmp[key[i]]["name"]);	
	}
}

void do_info(object me,object who,string arg)
{
	int i,size,k;
	string fam_name,id;
	mapping mpTmp;
	if ( me->get("fam_name") != who->get_fam_name() )
		return ;
	fam_name = me->get("fam_name");
	mpTmp = get_save_2("elect."+fam_name);
	if ( !mapp(mpTmp) )
		return ;
	if ( sscanf(arg,"%d.%s.%s",k,id,arg) != 3 )
	{
		if ( sscanf(arg,"%d.%s",k,id) != 2 )
			return;
	}
	if ( !mapp(mpTmp[id]) )
		return ;
	if ( k == 1 )
	{
		if ( stringp(mpTmp[id]["info"]) )
			send_user(who,"%c%c%d%d%s",0xA0,2,to_int(id),getoid(me),mpTmp[id]["info"]);
		else
			send_user(who,"%c%c%d%d%s",0xA0,2,to_int(id),getoid(me),"");
	}
	else if ( k == 2 )
	{
		if ( sizeof(arg) > 120 )
		{
			send_user(who,"%c%s",'!',"竞选词太长了,请减少字数");
			return ;
		}
		if ( strstr(arg,".") != -1 )
		{
			send_user(who,"%c%s",'!',"不能有非法字符");
			return ;
		}
		if ( mpTmp[id]["level"] != who->get_level() )
			set_save_2(sprintf("elect.%s.%s.level",fam_name,id),who->get_level());
		set_save_2(sprintf("elect.%s.%s.info",fam_name,id),arg);
		save();
	}	
}

void do_vote(object me,object who,string arg)
{
	int level,p;
	string id,name,fam_name;

	if ( me->get("fam_name") != who->get_fam_name() )
		return ;	
	if ( !stringp(arg) )
		return ;
	id = arg;
	if ( who->get_save("shouxivote") == iTimes )
	{
		send_user(who,"%c%s",'!',"您已经投过票了！");	
		return;
	}
	fam_name = who->get_fam_name();
	level = who->get_level();
	if ( sizeof(fam_name) == 0 || level < 10 )
	{
		send_user(who,"%c%s",'!',"您没有投票资格！");	
		return;
	}
	if ( !mapp(get_save_2(sprintf("elect.%s.%s",fam_name,id))) )	//不存在
		return ;
	if ( level < 30 )
		p = 1;
	else if ( level < 60 )
		p = 2;		
	else if ( level < 90 )
		p = 3;	
	else if ( level < 120 )
		p = 4;
	else if ( level <= 150 )
		p = 5;
	add_save_2(sprintf("elect.%s.%s.point",fam_name,id),p);	
	who->set_save("shouxivote",iTimes);
	save();
	name = get_save_2(sprintf("elect.%s.%s.name",fam_name,id));
	FAMILY_D->family_channel( fam_name, 0, CHAT + sprintf("%s玩家在评选首席大弟子中投了%s一票，%s玩家称谓积分增加%d分",who->get_name(),name,name,p) );
	send_user(who,"%c%c%d%d%w%w%s",0xA0,1,to_int(id),getoid(me),get_save_2(sprintf("elect.%s.%s.level",fam_name,id)),get_save_2(sprintf("elect.%s.%s.point",fam_name,id)));
	log_file("schoolvote.txt",sprintf("%s %s %s 投票 %s 得分 %d 总分 %d\n",short_time(),fam_name,who->get_name(),name,p,get_save_2(sprintf("elect.%s.%s.point",fam_name,id))));
}

// 函数：票数比对 降序
int vote_cmp( string key1, string key2 )
{
        return get_save_2(sprintf("elect.%s.%s.point",cTmp,key2)) - get_save_2(sprintf("elect.%s.%s.point",cTmp,key1));
}
//选举结果
void open_vote()
{
	int i,size;
	string *key;

	for(i=0,size=sizeof(SchoolName);i<size;i++)
	{
		if ( sizeof(get_save_2(sprintf("elect.%s",SchoolName[i]))) == 0 )
			continue;
		cTmp = SchoolName[i];
		key = sort_array( keys(get_save_2(sprintf("elect.%s",SchoolName[i]))), (: vote_cmp($1, $2) :) );
		set_save_2(sprintf("winners.%s.name",SchoolName[i]),get_save_2(sprintf("elect.%s.%s.name",SchoolName[i],key[0])) );
		set_save_2(sprintf("winners.%s.armorcode",SchoolName[i]),get_save_2(sprintf("elect.%s.%s.armorcode",SchoolName[i],key[0])) );
		set_save_2(sprintf("winners.%s.level",SchoolName[i]),get_save_2(sprintf("elect.%s.%s.level",SchoolName[i],key[0])) );
		set_save_2(sprintf("winners.%s.id",SchoolName[i]),key[0] );
		set_save_2(sprintf("winners.%s.family",SchoolName[i]),SchoolName[i] );
		set_save_2(sprintf("winners.%s.point",SchoolName[i]),get_save_2(sprintf("elect.%s.%s.point",SchoolName[i],key[0])) );
		log_file("schoolvote.txt",sprintf("%s %s 首席大弟子: %s %s \n",short_time(),SchoolName[i],key[0],get_save_2(sprintf("elect.%s.%s.name",SchoolName[i],key[0]))));
	}
	save();
}
//开始新投票
void start_vote()
{
	int i,size,*nTmp;
	string id;
	mapping mpTmp;
	delete_save_2("elect");
	for(i=0,size=sizeof(SchoolName);i<size;i++)
	{
		log_file("schoolvote.txt",sprintf("%s %s 开始新一轮竞选\n",short_time(),SchoolName[i],));
		mpTmp = get_save_2(sprintf("winners.%s",SchoolName[i]));
		if ( !mapp(mpTmp) )
			continue;
		id = mpTmp["id"];
		set_save_2(sprintf("elect.%s.%s.name",SchoolName[i],id),mpTmp["name"]);
		set_save_2(sprintf("elect.%s.%s.armorcode",SchoolName[i],id),mpTmp["armorcode"]);
		set_save_2(sprintf("elect.%s.%s.level",SchoolName[i],id),mpTmp["level"]);
	}
	save();		
}
//生成首席弟子
void generate_shouxi()
{
	int i,size,*nTmp,z;
	string name;
	object npc;
	
	for(i=0,size=sizeof(SchoolName);i<size;i++)
	{
		if ( !objectp(npc=get(SchoolName[i])) )
		{
			npc = new("npc/school/0001");
			if ( !npc )
				break;
			set(SchoolName[i],npc);
		}
		npc->set("fam_name",SchoolName[i]);
		nTmp = mpPos[SchoolName[i]];
		if( stringp(name=get_save_2(sprintf("winners.%s.name",SchoolName[i]))) )
		{
			npc->set_name(SchoolName[i]+"首席大弟子");
			npc->set_real_name(name);
			if (z=get_save_2(sprintf("winners.%s.armorcode",SchoolName[i])))
				npc->set_armor_code(z);
			else
				npc->set_armor_code(mpPic[SchoolName[i]]);
		}
		else
		{
			npc->set_name("首席大弟子");
			npc->set_armor_code(mpPic[SchoolName[i]]);
		}
		npc->add_to_scene(nTmp[0],nTmp[1],nTmp[2],nTmp[3]);
		set_block(nTmp[0], nTmp[1], nTmp[2], FLY_BLOCK);
	}
}

void before_destruct()
{
	int i,size;
	object npc;
	for(i=0,size=sizeof(SchoolName);i<size;i++)
	{
		if ( !objectp(npc=get(SchoolName[i])) )
			continue;
		npc->remove_from_scene();
		destruct(npc);
	}
}



void do_exchange(object me, object who,string arg)
{
	int i,id,p,p1,p2,picid;
	object item;
	string cTmp,fam_name,name;
	i = to_int(arg);
	id = getoid(me);
	if ( (fam_name=me->get("fam_name")) != who->get_fam_name() )
		return ;
	if ( (picid=me->get_armor_code()) == 0 )
		picid = mpPic[fam_name];
	name = me->get_real_name()?me->get_real_name():me->get_name();
	if ( i == 0 )
	{
		send_user( who, "%c%c%w%s", ':',3,picid,name+":\n    师弟！师傅见你近日勤学苦练，为发扬光大本门着实贡献不少，师傅在此准备了些宝物作为奖励，这些奖励你须用门派贡献点换取。\n"+
			sprintf(ESC"12点兑换藏宝图\ntalk %x# exchange.1\n",id) +
			sprintf(ESC"64点兑换技能进阶书\ntalk %x# exchange.2\n",id) +
			sprintf(ESC"12点兑换高级药品一个\ntalk %x# exchange.3\n",id) +
			ESC"离开");			
		return;
	}
	if ( i == 1 )
	{
		cTmp = 	"item/std/8000";
		p1 = 12;
	}
	else if ( i == 2 )
	{
		cTmp = BOOK_FILE->get_book_file();
		p1 = 64;
	}
	else if ( i == 3 )
	{
		cTmp = nDrugs[random(sizeof(nDrugs))];
		p1 = 12;
	}
	else
		return ;
	if ( !stringp(cTmp) )
		return ;
	if ( (p2=who->get_fam_contribute()) < p1 )
	{
		send_user(who,"%c%s",'!',"您的门派贡献点不足！");	
		return ;
	}
	item = new(cTmp);
	if ( !item )
		return;
	p = item->move(who,-1);
	if ( !p )
	{
		send_user(who,"%c%s",'!',"你携带的物品太多了！");	
		return ;
	}
	send_user(who,"%c%s",'!',"您成功兑换了"+item->get_name());	
	item->add_to_user(p);
	who->set_fam_contribute(p2-p1);
	
}

int can_betray(object who)
{
	string fam_name;
	fam_name = who->get_fam_name();
	if ( sizeof(fam_name) == 0 )
		return 1;
	if ( mapp(get_save_2(sprintf("elect.%s.%d",fam_name,who->get_number()))) )
	{
		send_user(who,"%c%s",'!',"你参加了首席大弟子的竞选，不能背叛师门！");
		return 0;
	}
	return 1;
}
//领取师门称谓
void get_hornor(object me, object who,string arg)
{
	string fam_name,cTitle,name;
	mapping mpTmp;
	int level,point,flag,id,picid;
	
	if ( (fam_name=me->get("fam_name")) != who->get_fam_name() )
		return ;
	if ( (picid=me->get_armor_code()) == 0 )
		picid = mpPic[fam_name];
	id = getoid(me);
	flag = to_int(arg);
	name = me->get_real_name()?me->get_real_name():me->get_name();
	if ( flag == 0 )
	{
		send_user( who, "%c%c%w%s", ':',3,picid,name+":\n    鉴于师弟最近的表现，师傅甚是满意，为了肯定师弟所作出的努力，师傅决定给予你相应的称号。\n"+
			sprintf(ESC"领取一级称谓\ntalk %x# hornor.1\n",id) +
			sprintf(ESC"领取二级称谓\ntalk %x# hornor.2\n",id) +
			sprintf(ESC"领取三级称谓\ntalk %x# hornor.3\n",id) +
			sprintf(ESC"领取四级称谓\ntalk %x# hornor.4\n",id) +
			sprintf(ESC"领取首席称谓\ntalk %x# hornor.9\n",id) +
			ESC"离开");	
		return ;			
	}
	else if ( flag == 9 )
	{
		//领取首席称谓
		mpTmp = get_save_2(sprintf("winners.%s",fam_name));
		if ( iTimes != who->get_save("sxTimes") && mapp(mpTmp) && to_int(mpTmp["id"]) == who->get_number() )
		{
			who->set_save("sxTimes",iTimes);
			who->set_save("sxFamily",fam_name);
			TITLE_D->add_shouxi_title(who,fam_name);
			send_user(who,"%c%s",'!',"你领取了首席大弟子的称谓");
		}
		return ;
	}
	else if ( flag == 1 )
	{
		level = 30;
		point = 150;
	}
	else if ( flag == 2 )
	{
		level = 60;
		point = 300;
	}
	else if ( flag == 3 )
	{
		level = 90;
		point = 600;
	}
	else if ( flag == 4 )
	{
		level = 120;
		point = 1200;
	}
	else
		return ;
	if ( who->get_level() < level )
	{
		send_user(who,"%c%s",'!',"您的级别不够！");
		return ;
	}
	if ( who->get_fam_contribute() < point )
	{
		send_user(who,"%c%s",'!',sprintf("您的门派贡献点不足%d点！",point));
		return ;
	}
	cTitle = who->get_fam_title();
	if ( sizeof(cTitle)== 4 )
	{
		if ( to_int(cTitle[2..2]) >= flag )
		{
			send_user(who,"%c%s",'!',"您不能领取这个级别的称谓！");
			return ;
		}
		who->delete_title(cTitle);
	}
	cTitle = sprintf("S%d%d%d",who->get_fam_type(),flag,who->get_gender());
	who->add_title(cTitle);
	who->set_fam_title(cTitle);	
	send_user(who,"%c%s",'!',sprintf("您成功领取了%d级称谓！",flag));
}
//检查首席称谓
void check_shouxi_title(object who)
{
	string fam_name;
	fam_name=who->get_fam_name();
	if ( iTimes == who->get_save("sxTimes") &&  fam_name == who->get_save("sxFamily") )
		return ;
	who->delete_save("sxTimes");
	who->delete_save("sxFamily");
	who->delete_title(TITLE_D->get_shouxi_titlecode(fam_name));
}
//test
void test_add_elect(object who)
{
	int i;
	for(i=0;i<10;i++)
	{
		set_save_2(sprintf("elect.蜀山.%d.name",i),sprintf("test%d",i));		
		set_save_2(sprintf("elect.蜀山.%d.level",i),i*10);
	}
	tell_user(who,"ok!");

	save();
}

void test_times()
{
	iTimes = 0;
}
