//称谓处理模块
#include <ansi.h>

//称谓编码表
mapping mpTitle = ([
	
	"A001"	:	"打虎英雄",
	"A002"	:	"威武天下",
	"A003"	:	"劳动最光荣",
	"A004"	:	"勤劳的小蜜蜂",
	"A005"	:	"爆强的战国劳模",
	"A006"	:	"超级无敌跑镖大超人",
	"A007"	:	"地狱少年",
	"A008"	:	"地狱少女",
	"A009"	:	"青铜圣斗士",
	"A010"	:	"白银圣斗士",
	"A011"	:	"黄金圣斗士",
	"A012"	:	"暗黑圣斗士",
	"A013"	:	"一马平川",	//真假虎王的称谓
	"A014"	:	"二龙戏珠",
	"A015"	:	"入木三分",
	"A016"	:	"遨游四海",
	"A017"	:	"武松打虎",
	"A018"	:	"过五关斩六将",
		
	"A020" 	:	"天下第一",
	"A021" 	:	"富甲天下",
	"A022" 	:	"功德无量",
	"A023" 	:	"桃李满天下",
		
	"B001"	:	"师傅",		//拜师的称谓
	"B002"	:	"徒弟",
	"B003"	:	"为人师表",
	"B004"	:	"桃李天下",
	
	"C001"	: 	"帮主",		// 帮派
	"C002"	: 	"副帮主",
	"C003"	: 	"长老",
	"C004"	: 	"堂主",
	"C005"	: 	"香主",
	"C006"	: 	"精英",
	"C007"	: 	"商人",
	"C008"	: 	"帮众",
	
	"F001"	:	"桃花源首席大弟子",
	"F002"	:	"蜀山首席大弟子",
	"F003"	:	"禁卫军首席大弟子",
	"F004"	:	"唐门首席大弟子",
	"F005"	:	"茅山首席大弟子",
	"F006"	:	"昆仑山首席大弟子",
	"F007"	:	"云梦泽首席大弟子",
	
	"G001"	:	"全家英雄",
	"G002"	:	"乱世英雄", 
	"G003"	:	"游戏在线GM",
	"G004"	: 	"游戏开发人员",
	"G005"	:	"线上活动主持人",
	"G006"	:	"游戏巡察人员",
	"G007"	:	"封测第一帮",
	
	"M001"	:	"相公",
	"M002"	:	"娘子",
	
	"P001"	:	"战国新兵",
	"P002"	:	"伍长",
	"P003"	:	"百夫长",
	"P004"	:	"千夫长",
	"P005"	:	"偏将军",
	"P006"	:	"平国将军",
	"P007"	:	"安国将军",
	"P008"	:	"镇国将军",
	"P009"	:	"征夷将军",
	"P010"	:	"骠骑大将军",
	"P011"	:	"天下大将军",
		
	"S111"	:	"引路小童",	//桃花源门派称谓
	"S112"	:	"擎花仕女",
	"S121"	:	"桃园力士",
	"S122"	:	"楚楚伊人",
	"S131"	:	"逍遥散仙",
	"S132"	:	"蕙质兰心",
	"S141"	:	"世外真人",
	"S142"	:	"倾国倾城",

	"S211"	:	"山涧灵童",	//蜀山门派称谓
	"S212"	:	"山溪灵鱼",
	"S221"	:	"江湖游侠",
	"S222"	:	"碧天女侠",
	"S231"	:	"通神道者",
	"S232"	:	"唤神使者",
	"S241"	:	"天外飞仙",
	"S242"	:	"九天仙女",

	"S311"	:	"巡城小兵",	//禁卫军门派称谓
	"S312"	:	"传令信使",
	"S321"	:	"禁军教头",
	"S322"	:	"禁军侍卫",
	"S331"	:	"执法军门",
	"S332"	:	"飒爽英侠",
	"S341"	:	"神威将军",
	"S342"	:	"巾帼英豪",

	"S411"	:	"门前侍者",	//唐门门派称谓
	"S412"	:	"小家碧玉",
	"S421"	:	"夺命神手",
	"S422"	:	"绣阁千金",
	"S431"	:	"无影神宗",
	"S432"	:	"婀娜华容",
	"S441"	:	"八臂罗汉",
	"S442"	:	"至尊红颜",

	"S511"	:	"茅山小道",	//茅山门派称谓
	"S512"	:	"采花小仙",
	"S521"	:	"护法行者",
	"S522"	:	"幽兰丽人",
	"S531"	:	"降魔尊者",
	"S532"	:	"驱魔女使",
	"S541"	:	"御法天师",
	"S542"	:	"惊世玉姬",

	"S611"	:	"三清道童",	//昆仑山门派称谓
	"S612"	:	"玉清秀女",
	"S621"	:	"御龙使者",
	"S622"	:	"御龙仙子",
	"S631"	:	"火龙法神",
	"S632"	:	"珈珞使者",
	"S641"	:	"神龙法尊",
	"S642"	:	"飞天圣女",

	"S711"	:	"药谷顽孩",	//云梦泽门派称谓
	"S712"	:	"鬼灵精怪",
	"S721"	:	"回命圣手",
	"S722"	:	"冰雪可人",
	"S731"	:	"鬼谷神医",
	"S732"	:	"素手奇才",
	"S741"	:	"济世医尊",
	"S742"	:	"渡世观音",
	
	"V001"	: 	"ＶＩＰ",
		
	"X"	:	"评价头衔",
						
	"Z001"	:	"战国功勋元老",
	"Z002"	:	"战国新人王",
	"Z003"	: 	"战国裁缝大师",		
	"Z004"	: 	"战国打造大师",		
	"Z005"	: 	"战国炼丹大师",		
	"Z006"	: 	"战国机关大师",		
	"Z007"	: 	"战国酒食大师",		
	"Z008"	: 	"大话战国第一帮主",
	"Z009"	: 	"截图尊者",
	"Z010"	: 	"创意使者",
	"Z011"	: 	"战国才子",
	"Z012"	: 	"战国才女",
	"Z013"	: 	"战国石刻大师",
	"Z014"	: 	"战国王者",
	"Z888"	:	"无双城主",
	"Z889"	:	"无双城校尉",
			
	

		]);
mapping mpShouxi = ([
	"桃花源"	:	"F001",
	"蜀山"		:	"F002",
	"禁卫军"	:	"F003",
	"唐门"		:	"F004",
	"茅山"		:	"F005",
	"昆仑山"	:	"F006",
	"云梦泽"	:	"F007",

		]);

// 函数：生成二进制码
void SAVE_BINARY() { }

// 函数：构造处理
void create() 
{ 

}
//检查代码是否有效
int check_title_code(string titlecode)
{
	return stringp(mpTitle[titlecode])?1:0;
}
//增加玩家称谓
void send_title(object who, string titlecode)
{
	string titlename, name;
	int position;
	if ( titlecode[0..0] == "B" )
	{
		if ( titlecode == "B002" )
			titlename = CRA + who->get_save_2("baishi.shifu.name")+"的徒弟";
		else
			titlename = CRA + mpTitle[titlecode];
	}
	else
	if ( titlecode[0..0] == "C" )
	{
		name = who->get_org_name();
		if (name!="")
		{
			titlename = CRE + name + mpTitle[titlecode];
		}
	}
	else
	if ( titlecode[0..0] == "M" )
	{
		name = who->get_save_2("marry.name");
		if ( stringp(name) && name != "" )
		{
			if ( titlecode == "M001" )
				titlename = CRD + name+"的相公";
			else if ( titlecode == "M002" )
				titlename = CRD + name+"的娘子";
		}
	}
	else
	if ( titlecode[0..0] == "X" )
		titlename = USER_RANK_D->get_rank(who);
	else
		titlename = mpTitle[titlecode];
	if ( sizeof(titlename) == 0 )
		return ;
	if ( titlecode[0..0] == "A" || titlecode[0..0] == "Z" )
		titlename = CRF + titlename;		
	send_user(who,"%c%c%s",0xA2,1,sprintf("%-4s%s",titlecode,titlename));
}
//删除玩家称谓
void delete_title(object who, string titlecode)
{
	string titlename;
	
	titlename = mpTitle[titlecode];
	if ( sizeof(titlename) == 0 )
		return ;
	send_user(who,"%c%c%s",0xA2,2,titlecode);
}
//显示称谓(不同类别的称谓代码可以拼成不同的称谓名称)
void show_title(object who, string titlecode)
{
	string titlename, name,tmp_title_code;
	int position,rank;
	string *mingren_titlecode=({"A020","A021","A022","A023","F001","F002","F003","F004","F005","F006","F007",});
	
	who->delete("add_mingren_power");
	USER_ENERGY_D->count_ap(who);
	USER_ENERGY_D->count_cp(who);
	if ( titlecode[0..0] == "P" )
	{
		sscanf(titlecode,"P%d",rank);
		if ( rank < 4 )
			titlename = HIW + mpTitle[titlecode];
		else if ( rank < 7 )
			titlename = HIG + mpTitle[titlecode];
		else if ( rank < 9 )
			titlename = HIB + mpTitle[titlecode];
		else if ( rank < 11 )
			titlename = HIY + mpTitle[titlecode];
		else
			titlename = PPM + mpTitle[titlecode];
	}
	else
	if ( titlecode[0..0] == "B" )
	{
		if ( titlecode == "B002" )
			titlename = CRA + who->get_save_2("baishi.shifu.name")+"的徒弟";
		else
			titlename = CRA + mpTitle[titlecode];
	}
	else
	if ( titlecode[0..0] == "C" )
	{
		name = who->get_org_name();
		if (name!="")
		{
			titlename = CRE + name + mpTitle[titlecode];
		}
	}
	else
	if ( titlecode[0..0] == "M" )
	{
		name = who->get_save_2("marry.name");
		if ( stringp(name) && name != "" )
		{
			if ( titlecode == "M001" )
				titlename = CRD + name+"的相公";
			else if ( titlecode == "M002" )
				titlename = CRD + name+"的娘子";
		}
	}	
	else
	if ( titlecode[0..0] == "X" )
		titlename = USER_RANK_D->get_rank(who);	
	else	
	titlename = mpTitle[titlecode];	
	if ( sizeof(titlename) == 0 )
		return ;
	if ( titlecode[0..0] == "A" || titlecode[0..0] == "Z" )
		titlename = CRF + titlename;
	else if ( titlecode == "V001" )
		titlename = HIY + titlename;
	tmp_title_code = who->get_title_code();
	who->set_title(titlecode,titlename);
	if(tmp_title_code == "A018" || titlecode == "A018") 
	{			//	此称号所具有的附加属性
		USER_ENERGY_D->count_dp(who);
		USER_ENERGY_D->count_pp(who);
	}
	if(member_array(titlecode,mingren_titlecode)!=-1)
	{			//称号为名人堂称谓ap,cp加成
		who->set("add_mingren_power",1);
		USER_ENERGY_D->count_ap(who);
		USER_ENERGY_D->count_cp(who);
	}
	who->add_to_scene(get_z(who),get_x(who),get_y(who));
}
//隐藏称谓
void hide_title(object who, string titlecode)
{
	if(who->get_title_code() == "A018") 
	{		//	此称号所具有的附加属性
		who->set_title("","");
		USER_ENERGY_D->count_dp(who);
		USER_ENERGY_D->count_pp(who);
	} 
	else 
	{
		who->delete("add_mingren_power");
		USER_ENERGY_D->count_ap(who);
		USER_ENERGY_D->count_cp(who);
		who->set_title("","");
	}
	who->add_to_scene(get_z(who),get_x(who),get_y(who),get_d(who));
}
//获得称谓名称
string get_titlename(string titlecode)
{
	string titlename;
	
	titlename = mpTitle[titlecode];
	if ( sizeof(titlename) == 0 )
		return "";	
	return titlename;	
}

void add_shouxi_title(object who, string fam_name)
{
	who->add_title(mpShouxi[fam_name]);	
}

string get_shouxi_titlecode(string fam_name)
{
	return 	mpShouxi[fam_name];
}
