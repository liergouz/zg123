//��ν����ģ��
#include <ansi.h>

//��ν�����
mapping mpTitle = ([
	
	"A001"	:	"��Ӣ��",
	"A002"	:	"��������",
	"A003"	:	"�Ͷ������",
	"A004"	:	"���͵�С�۷�",
	"A005"	:	"��ǿ��ս����ģ",
	"A006"	:	"�����޵����ڴ���",
	"A007"	:	"��������",
	"A008"	:	"������Ů",
	"A009"	:	"��ͭʥ��ʿ",
	"A010"	:	"����ʥ��ʿ",
	"A011"	:	"�ƽ�ʥ��ʿ",
	"A012"	:	"����ʥ��ʿ",
	"A013"	:	"һ��ƽ��",	//��ٻ����ĳ�ν
	"A014"	:	"����Ϸ��",
	"A015"	:	"��ľ����",
	"A016"	:	"�����ĺ�",
	"A017"	:	"���ɴ�",
	"A018"	:	"�����ն����",
		
	"A020" 	:	"���µ�һ",
	"A021" 	:	"��������",
	"A022" 	:	"��������",
	"A023" 	:	"����������",
		
	"B001"	:	"ʦ��",		//��ʦ�ĳ�ν
	"B002"	:	"ͽ��",
	"B003"	:	"Ϊ��ʦ��",
	"B004"	:	"��������",
	
	"C001"	: 	"����",		// ����
	"C002"	: 	"������",
	"C003"	: 	"����",
	"C004"	: 	"����",
	"C005"	: 	"����",
	"C006"	: 	"��Ӣ",
	"C007"	: 	"����",
	"C008"	: 	"����",
	
	"F001"	:	"�һ�Դ��ϯ�����",
	"F002"	:	"��ɽ��ϯ�����",
	"F003"	:	"��������ϯ�����",
	"F004"	:	"������ϯ�����",
	"F005"	:	"éɽ��ϯ�����",
	"F006"	:	"����ɽ��ϯ�����",
	"F007"	:	"��������ϯ�����",
	
	"G001"	:	"ȫ��Ӣ��",
	"G002"	:	"����Ӣ��", 
	"G003"	:	"��Ϸ����GM",
	"G004"	: 	"��Ϸ������Ա",
	"G005"	:	"���ϻ������",
	"G006"	:	"��ϷѲ����Ա",
	"G007"	:	"����һ��",
	
	"M001"	:	"�๫",
	"M002"	:	"����",
	
	"P001"	:	"ս���±�",
	"P002"	:	"�鳤",
	"P003"	:	"�ٷ�",
	"P004"	:	"ǧ��",
	"P005"	:	"ƫ����",
	"P006"	:	"ƽ������",
	"P007"	:	"��������",
	"P008"	:	"�������",
	"P009"	:	"���Ľ���",
	"P010"	:	"����󽫾�",
	"P011"	:	"���´󽫾�",
		
	"S111"	:	"��·Сͯ",	//�һ�Դ���ɳ�ν
	"S112"	:	"�滨��Ů",
	"S121"	:	"��԰��ʿ",
	"S122"	:	"��������",
	"S131"	:	"��ңɢ��",
	"S132"	:	"ޥ������",
	"S141"	:	"��������",
	"S142"	:	"������",

	"S211"	:	"ɽ����ͯ",	//��ɽ���ɳ�ν
	"S212"	:	"ɽϪ����",
	"S221"	:	"��������",
	"S222"	:	"����Ů��",
	"S231"	:	"ͨ�����",
	"S232"	:	"����ʹ��",
	"S241"	:	"�������",
	"S242"	:	"������Ů",

	"S311"	:	"Ѳ��С��",	//���������ɳ�ν
	"S312"	:	"������ʹ",
	"S321"	:	"������ͷ",
	"S322"	:	"��������",
	"S331"	:	"ִ������",
	"S332"	:	"�ˬӢ��",
	"S341"	:	"��������",
	"S342"	:	"����Ӣ��",

	"S411"	:	"��ǰ����",	//�������ɳ�ν
	"S412"	:	"С�ұ���",
	"S421"	:	"��������",
	"S422"	:	"���ǧ��",
	"S431"	:	"��Ӱ����",
	"S432"	:	"��Ȼ���",
	"S441"	:	"�˱��޺�",
	"S442"	:	"�������",

	"S511"	:	"éɽС��",	//éɽ���ɳ�ν
	"S512"	:	"�ɻ�С��",
	"S521"	:	"��������",
	"S522"	:	"��������",
	"S531"	:	"��ħ����",
	"S532"	:	"��ħŮʹ",
	"S541"	:	"������ʦ",
	"S542"	:	"������",

	"S611"	:	"�����ͯ",	//����ɽ���ɳ�ν
	"S612"	:	"������Ů",
	"S621"	:	"����ʹ��",
	"S622"	:	"��������",
	"S631"	:	"��������",
	"S632"	:	"����ʹ��",
	"S641"	:	"��������",
	"S642"	:	"����ʥŮ",

	"S711"	:	"ҩ���红",	//���������ɳ�ν
	"S712"	:	"���龫��",
	"S721"	:	"����ʥ��",
	"S722"	:	"��ѩ����",
	"S731"	:	"�����ҽ",
	"S732"	:	"�������",
	"S741"	:	"����ҽ��",
	"S742"	:	"��������",
	
	"V001"	: 	"�֣ɣ�",
		
	"X"	:	"����ͷ��",
						
	"Z001"	:	"ս����ѫԪ��",
	"Z002"	:	"ս��������",
	"Z003"	: 	"ս���÷��ʦ",		
	"Z004"	: 	"ս�������ʦ",		
	"Z005"	: 	"ս��������ʦ",		
	"Z006"	: 	"ս�����ش�ʦ",		
	"Z007"	: 	"ս����ʳ��ʦ",		
	"Z008"	: 	"��ս����һ����",
	"Z009"	: 	"��ͼ����",
	"Z010"	: 	"����ʹ��",
	"Z011"	: 	"ս������",
	"Z012"	: 	"ս����Ů",
	"Z013"	: 	"ս��ʯ�̴�ʦ",
	"Z014"	: 	"ս������",
	"Z888"	:	"��˫����",
	"Z889"	:	"��˫��Уξ",
			
	

		]);
mapping mpShouxi = ([
	"�һ�Դ"	:	"F001",
	"��ɽ"		:	"F002",
	"������"	:	"F003",
	"����"		:	"F004",
	"éɽ"		:	"F005",
	"����ɽ"	:	"F006",
	"������"	:	"F007",

		]);

// ���������ɶ�������
void SAVE_BINARY() { }

// ���������촦��
void create() 
{ 

}
//�������Ƿ���Ч
int check_title_code(string titlecode)
{
	return stringp(mpTitle[titlecode])?1:0;
}
//������ҳ�ν
void send_title(object who, string titlecode)
{
	string titlename, name;
	int position;
	if ( titlecode[0..0] == "B" )
	{
		if ( titlecode == "B002" )
			titlename = CRA + who->get_save_2("baishi.shifu.name")+"��ͽ��";
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
				titlename = CRD + name+"���๫";
			else if ( titlecode == "M002" )
				titlename = CRD + name+"������";
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
//ɾ����ҳ�ν
void delete_title(object who, string titlecode)
{
	string titlename;
	
	titlename = mpTitle[titlecode];
	if ( sizeof(titlename) == 0 )
		return ;
	send_user(who,"%c%c%s",0xA2,2,titlecode);
}
//��ʾ��ν(��ͬ���ĳ�ν�������ƴ�ɲ�ͬ�ĳ�ν����)
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
			titlename = CRA + who->get_save_2("baishi.shifu.name")+"��ͽ��";
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
				titlename = CRD + name+"���๫";
			else if ( titlecode == "M002" )
				titlename = CRD + name+"������";
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
	{			//	�˳ƺ������еĸ�������
		USER_ENERGY_D->count_dp(who);
		USER_ENERGY_D->count_pp(who);
	}
	if(member_array(titlecode,mingren_titlecode)!=-1)
	{			//�ƺ�Ϊ�����ó�νap,cp�ӳ�
		who->set("add_mingren_power",1);
		USER_ENERGY_D->count_ap(who);
		USER_ENERGY_D->count_cp(who);
	}
	who->add_to_scene(get_z(who),get_x(who),get_y(who));
}
//���س�ν
void hide_title(object who, string titlecode)
{
	if(who->get_title_code() == "A018") 
	{		//	�˳ƺ������еĸ�������
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
//��ó�ν����
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
