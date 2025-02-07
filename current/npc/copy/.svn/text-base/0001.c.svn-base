#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>
#include <task.h>

inherit OFFICER;
int host_type;

// 函数：获取人物造型
int get_char_picid() { return 5501; }
void do_welcome(string arg);
void do_accept(string arg);
void do_query(string arg);

// 函数：构造处理
void create()
{
	object me=this_object();
        set_name("左丘明");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
                 "accept"         : (: do_accept :),
                 "query"         : (: do_query :),
        ]) );
        set("legend", ({ 32 }));
        setup();
	host_type = MAIN_D->get_host_type();
}

void do_look(object who)
{
	int id;
	string cmd="";
	object me=this_object();
	id = getoid(me);
	if ( who->get_legend(TASK_2_00,16) && !who->get_legend(TASK_2_00,17) ) 
		cmd = sprintf(ESC HIY "找我谈谈\ntalk %x# welcome.11\n",id);
	if ( who->get_legend(TASK_2_00,17) && !who->get_legend(TASK_2_00,18) ) 
		cmd = sprintf(ESC HIY "拜访周王\ntalk %x# welcome.13\n",id);
	if ( "sys/sys/count"->get_new_story() == 0 )
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    最近，我得到了一面叫做“封妖镜”的上古遗物。这面镜子里面封存了数百年以来因为战争而产生的镜妖和身上藏有许多宝物的残魄，如果拿一件真稀的装备在镜子前作法焚化的话，就可以进入封妖镜的镜像了。如果你也想到镜像里面探险的话，你就拿一件珍贵的装备给我，我帮你作法打开通往镜像的通道吧！\n"+ cmd +ESC"进入封妖镜\ntalk %x# welcome.1\n"ESC"什么是封妖镜\ntalk %x# welcome.2\n"ESC"消除镜像\ntalk %x# welcome.3\n"ESC"封妖镜的新改变\ntalk %x# welcome.20\n"ESC"离开",id,id,id,id));
	else
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    最近，我得到了一面叫做“封妖镜”的上古遗物。这面镜子里面封存了数百年以来因为战争而产生的镜妖和身上藏有许多宝物的残魄，如果拿一件真稀的装备在镜子前作法焚化的话，就可以进入封妖镜的镜像了。如果你也想到镜像里面探险的话，你就拿一件珍贵的装备给我，我帮你作法打开通往镜像的通道吧！\n"+ cmd +ESC"进入封妖镜\ntalk %x# welcome.1\n"ESC"什么是封妖镜\ntalk %x# welcome.2\n"ESC"消除镜像\ntalk %x# welcome.3\n"ESC"封妖镜的新改变\ntalk %x# welcome.20\n"ESC"重铸六大武器\ntalk %x# welcome.80\n"ESC"离开",id,id,id,id,id));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,tId,*nXy;
       	object who, item,map;
       	string cTmp,cFile;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 1:
        	tId = who->get_team_id();
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_MIRROR);
        		if ( map )
        		{
        			if ( who->get_level() < 35 )
        			{
 					send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    以你现在的实力，这样进入封妖镜是很危险的！等你的等级超过３５级了，我再让你去吧。\n"));
        				return ;	
        			}
        			nXy = map->get("exit");
        			who->add_to_scene(map->get_id(),nXy[0],nXy[1]);
        			return ;
        		}	
        	}
 		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    想进入封妖镜必须打开进入封妖镜的通道，要打开通道，就必须拿一件15级以上的珍稀的装备焚化作为触媒。你给予我一件珍贵程度以上的装备，我帮你把他焚化作为触媒打开通往封妖镜里面的通道吧！给予我装备，你懂得吗？\n"ESC"我懂得，给予是ALT+G！"));
        	break;
        case 2:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    封妖镜那个地方很危险，所以单独去的话就太凶险了，你必须要跟其他人组队，而且你的队员等级都超过３５级，我才可以让你去。但封妖镜的一个镜像只能容纳五个人进去，所以你的队伍是不可以超过五个人的。当你组成队伍之后，由你的队长给予我一件蓝色的珍稀装备，我就可以送你去封妖镜里面了。\n"ESC"我该给予你什么等级的装备？\ntalk %x# welcome.4\n"ESC"在里面冒险需要注意些什么？\ntalk %x# welcome.5\n"ESC"封妖镜里面我们会有什么挑战？\ntalk %x# welcome.6\n"ESC"离开",id,id,id));
        	break;
        case 3:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    如果你想消除镜像的话，你可以再给我一件珍稀装备用作焚化。就可以生成再生成新的镜像了。\n"ESC"离开",id,));
        	break;
        case 4:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    你焚化作为触媒的珍稀装备最少必须是15级以上蓝色程度的装备，而且你给我的装备的等级是很重要，因为用什么等级的装备作为触媒，就会生成对应等级怪物的聚集的镜像。所以你如果想遇到什么等级的妖怪，你就给予我对应等级的装备作为触媒吧！不过你也不必担心，因为里面遇见的一些残魄身上的宝物也很不错，如果你能打倒他，估计在他身上获得的装备也可以和你焚化的装备抵消了。\n"ESC"返回\ntalk %x# welcome.2\n"ESC"离开",id,));
        	break;
        case 5:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    因为封妖镜是一个邪气很重的地方，所以你必须在里面随时保持你的队伍团结，一旦你在镜像里面失去队伍了，你就不再可以留在那镜像里面了。\n"ESC"返回\ntalk %x# welcome.2\n"ESC"离开",id,));
        	break;
        case 6:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    据说里面封印了前几百年以来各个被灭掉的诸侯国家的亡灵的镜像，所以你在里面会遇上许多镜妖。而且听说只要你能把里面的镜像妖怪清除到一定比例，就会出现我所说的残魄。打倒这个残魄就可以获得一些不错的收获了！\n"ESC"返回\ntalk %x# welcome.2\n"ESC"离开",id,));
        	break;
        case 7:
        	tId = who->get_team_id();
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_MIRROR);
        		if ( map )
        		{
        			if ( who->get_level() < 35 )
        			{
 					send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    以你现在的实力，这样进入封妖镜是很危险的！等你的等级超过３５级了，我再让你去吧。\n"));
        				return ;	
        			}
        			nXy = map->get("exit");
        			who->add_to_scene(map->get_id(),nXy[0],nXy[1]);
        			return ;
        		}	
        	}
        	break;
	case 11:
		if ( who->get_legend(TASK_2_00,16) && !who->get_legend(TASK_2_00,17) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你也听说了封妖镜的传说？没错，这个宝物就在我手中，等你够强以后再来找我，我教你进入封妖镜的方法。\n"ESC"完成任务\ntalk %x# welcome.12\n"ESC"离开",me->get_name(),getoid(me)));
		break;
	case 12:
		if ( who->get_legend(TASK_2_00,16) && !who->get_legend(TASK_2_00,17) ) 
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_00,17);
			who->add_exp(300);
			who->add_potential(35);
			who->add_cash(500);
			send_user(who,"%c%s",';',sprintf("拜访左丘明 经验 300 潜能 35 金钱 500"));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,18,"" );
			me->do_welcome(13);
		}
		break;
	case 13:
		if ( who->get_legend(TASK_2_00,17) && !who->get_legend(TASK_2_00,18) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    战国乱世，群雄并起，昔日的周王室已经失去了号令天下的能力。当今周王姬延顺应世时，推出一套保险系统，希望能改变周国窘迫的现状，你要是有兴趣就去周王那里看看，会对你有好处的。顺着大路一直朝前走，周王就在尽头的宫殿里。\n"ESC"接受任务\ntalk %x# welcome.14\n"ESC"离开",me->get_name(),getoid(me)));
		break;		
	case 14:
		if ( who->get_legend(TASK_2_00,17) && !who->get_legend(TASK_2_00,18) ) 
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_2_00,18);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,19,"拜访周王" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"拜访周王");
		}
		break;	
	case 20:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    由于最近进入封妖镜镜像内的各国勇士不断努力，封妖镜的内的妖气已经开始减弱。现在，我们可以使用更低级的装备打开更高级的封妖镜镜像了。从现在开始，如果你想要打开一个相应等级的镜像，你只要给予我比你想要打开的相应等级镜像低20级的装备就可以了。\n"ESC"具体镜像开启规则？\ntalk %x# welcome.21\n"ESC"镜像内还有其他改变吗？\ntalk %x# welcome.22\n"ESC"返回\ntalk %x# welcome.2\n"ESC"离开",id,id,id));
		break;
	case 21:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    由于封妖镜内的妖气减弱了，所以从现在开始，如果你想要打开一个相应等级的镜像，你只要给予我比你想要打开的相应等级镜像低20级的装备就可以了。例如你要打开一个50级的镜像的话，你只要给我一个30级的蓝色程度以上装备就可以了。但是，我帮你打开的镜像的等级是不会超过你自身的等级的。\n"ESC"返回\ntalk %x# welcome.20\n"ESC"离开",id,));
		break;
	case 22:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    我听说，有的进入开启镜像的勇士最近曾经在把封妖镜内的镜妖全部清除后，遇见过一些称为“镜像首领”的强力镜妖，据说这些镜妖身上同样藏有非常珍贵的宝物。据我了解这个消息应该不假，勇士你不妨去尝试一下。\n"ESC"返回\ntalk %x# welcome.20\n"ESC"离开",id,));
		break;
	case 80:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    传说在封妖镜内蕴藏了6件威力惊人的六大武器，如果你有相应的材料；我就可以帮你重铸这些六大武器！\n"ESC"重铸玉晨宝剑\ntalk %x# welcome.81\n"ESC"重铸天尊宝刀\ntalk %x# welcome.82\n"ESC"重铸真君炽焰枪\ntalk %x# welcome.83\n"ESC"重铸乾坤无极棍\ntalk %x# welcome.84\n"ESC"重铸碧火寒月环\ntalk %x# welcome.85\n"ESC"重铸英杰拳刃\ntalk %x# welcome.86\n"ESC"离开",id,id,id,id,id,id,));
		break;
	case 81:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    重铸玉晨宝剑，需要材料是玉剑一把、鲁班宝石30个、干将宝石20个、欧冶宝石	20个，如果你拥有足够的材料，我就可以帮你重铸玉晨宝剑。\n"ESC"缴纳材料\ntalk %x# welcome.811\n"ESC"材料在哪里可以找到？\ntalk %x# welcome.812\n"ESC"离开",id,id));
		break;
	case 82:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    重铸天尊宝刀，需要材料是金刀一把、鲁班宝石30个、干将宝石20个、欧冶宝石	20个，如果你拥有足够的材料，我就可以帮你重铸天尊宝刀。\n"ESC"缴纳材料\ntalk %x# welcome.821\n"ESC"材料在哪里可以找到？\ntalk %x# welcome.822\n"ESC"离开",id,id));
		break;
	case 83:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    重铸真君炽焰枪，需要材料是赤缨枪一把、鲁班宝石30个、干将宝石20个、欧冶宝石	20个，如果你拥有足够的材料，我就可以帮你重铸真君炽焰枪。\n"ESC"缴纳材料\ntalk %x# welcome.831\n"ESC"材料在哪里可以找到？\ntalk %x# welcome.832\n"ESC"离开",id,id));
		break;				
	case 84:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    重铸乾坤无极棍，需要材料是古方棍一条、鲁班宝石30个、干将宝石20个、欧冶宝石	20个，如果你拥有足够的材料，我就可以帮你重铸乾坤无极棍。\n"ESC"缴纳材料\ntalk %x# welcome.841\n"ESC"材料在哪里可以找到？\ntalk %x# welcome.842\n"ESC"离开",id,id));
		break;
	case 85:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    重铸碧火寒月环，需要材料是月环一把、鲁班宝石30个、干将宝石20个、欧冶宝石	20个，如果你拥有足够的材料，我就可以帮你重铸碧火寒月环。\n"ESC"缴纳材料\ntalk %x# welcome.851\n"ESC"材料在哪里可以找到？\ntalk %x# welcome.852\n"ESC"离开",id,id));
		break;
	case 86:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    重铸英杰拳刃，需要材料是石雕拳刃一套、鲁班宝石30个、干将宝石20个、欧冶宝石	20个，如果你拥有足够的材料，我就可以帮你重铸英杰拳刃。\n"ESC"缴纳材料\ntalk %x# welcome.861\n"ESC"材料在哪里可以找到？\ntalk %x# welcome.862\n"ESC"离开",id,id));
		break;		
	case 811:
	case 821:
	case 831:
	case 841:
	case 851:
	case 861:
		if ( flag == 811 )
		{
			cTmp = "玉剑";
			cFile = "item/73/9075";
		}
		else if ( flag == 821 )
		{
			cTmp = "金刀";
			cFile = "item/72/9075";
		}
		else if ( flag == 831 )
		{
			cTmp = "赤缨枪";
			cFile = "item/74/9075";
		}
		else if ( flag == 841 )
		{
			cTmp = "古方棍";
			cFile = "item/75/9075";
		}
		else if ( flag == 851 )
		{
			cTmp = "月环";
			cFile = "item/71/9075";
		}
		else if ( flag == 861 )
		{
			cTmp = "石雕拳刃";
			cFile = "item/70/9075";
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 ||
			TASK_LEGEND_D->check_task_item_amount(who,"鲁班宝石") < 30 ||
			TASK_LEGEND_D->check_task_item_amount(who,"干将宝石") < 20 ||
			TASK_LEGEND_D->check_task_item_amount(who,"欧冶宝石") < 20 )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    重铸%s需要%s一把，鲁班宝石30个，干将宝石20个，欧冶宝石20个，你身上好像没有足够的材料吧？\n"ESC"离开",cFile->get_name(),cTmp));
			return ;	
		}
		TASK_LEGEND_D->check_task_item1(who,cTmp,1);
		TASK_LEGEND_D->check_task_item1(who,"鲁班宝石",30);
		TASK_LEGEND_D->check_task_item1(who,"干将宝石",20);
		TASK_LEGEND_D->check_task_item1(who,"欧冶宝石",20);
		item = new(cFile);
		item->set_hide(0);
		item->set_bind(4);
		i = item->move(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;	
		}
		item->add_to_user(i);
		send_user(who,"%c%s",';',"恭喜你得到了神器"HIR+item->get_name());
		break;
	case 812:
	case 822:
	case 832:
	case 842:
	case 852:
	case 862:
		if ( flag == 812 )
			cTmp = "玉剑";
		else if ( flag == 822 )
			cTmp = "金刀";
		else if ( flag == 832 )
			cTmp = "赤缨枪";
		else if ( flag == 842 )
			cTmp = "古方棍";
		else if ( flag == 852 )
			cTmp = "月环";
		else if ( flag == 862 )
			cTmp = "石雕拳刃";
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("左丘明：\n    %s你可以通过击败最近在封妖镜内出现的首领级怪物得到；鲁班宝石听说在某珍宝铺有许多；干将宝石你可以在封妖镜内的战斗随机得到；欧冶宝石你只要击败封妖镜内的强力怪物，就可以找到。\n"ESC"离开",cTmp));
		break;
        }

}

int accept_object(object who, object item)
{
	return "/sys/copy/mirror"->accept_object(this_object(),who,item);
}

void do_accept( string arg )
{
	"/sys/copy/mirror"->do_accept(this_object(),this_player(),arg);
}

void do_query( string arg )
{
	"/sys/copy/mirror"->do_query(this_object(),this_player(),arg);
}
