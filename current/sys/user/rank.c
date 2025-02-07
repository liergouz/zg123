
#include <ansi.h>
#include <equip.h>

// ���������ɶ�������
void SAVE_BINARY() { }

string *RankTable = ({
        HIW "����һ��" NOR, HIB "����һ��" NOR, HIY "����һ��" NOR,
        HIW "��������" NOR, HIB "��������" NOR, HIY "��������" NOR,
        HIW "����ҳ�" NOR, HIB "����ҳ�" NOR, HIY "����ҳ�" NOR,
        HIW "��ѧէ��" NOR, HIB "��ѧէ��" NOR, HIY "��ѧէ��" NOR,
        HIW "�����ž�" NOR, HIB "�����ž�" NOR, HIY "�����ž�" NOR,
        HIW "��֪һ��" NOR, HIB "��֪һ��" NOR, HIY "��֪һ��" NOR,
        HIW "����ͨͨ" NOR, HIB "����ͨͨ" NOR, HIY "����ͨͨ" NOR,
        HIW "��ͨƤë" NOR, HIB "��ͨƤë" NOR, HIY "��ͨƤë" NOR,
        HIW "��������" NOR, HIB "��������" NOR, HIY "��������" NOR,
        HIW "������" NOR, HIB "������" NOR, HIY "������" NOR,
        HIW "����С��" NOR, HIB "����С��" NOR, HIY "����С��" NOR,
        HIW "�������" NOR, HIB "�������" NOR, HIY "�������" NOR,
        HIW "�������" NOR, HIB "�������" NOR, HIY "�������" NOR,
        HIW "��Ȼ���" NOR, HIB "��Ȼ���" NOR, HIY "��Ȼ���" NOR,
        HIW "���д��" NOR, HIB "���д��" NOR, HIY "���д��" NOR,
        HIW "��Ȼ��ͨ" NOR, HIB "��Ȼ��ͨ" NOR, HIY "��Ȼ��ͨ" NOR,
        HIW "�������" NOR, HIB "�������" NOR, HIY "�������" NOR,
        HIW "����Ⱥ��" NOR, HIB "����Ⱥ��" NOR, HIY "����Ⱥ��" NOR,
        HIW "����似" NOR, HIB "����似" NOR, HIY "����似" NOR,
        HIW "�����뻯" NOR, HIB "�����뻯" NOR, HIY "�����뻯" NOR,
        HIW "һ����ʦ" NOR, HIB "һ����ʦ" NOR, HIY "һ����ʦ" NOR,
        HIW "����Ⱥ��" NOR, HIB "����Ⱥ��" NOR, HIY "����Ⱥ��" NOR,
        HIW "�񹦸���" NOR, HIB "�񹦸���" NOR, HIY "�񹦸���" NOR,
        HIW "�Ƿ��켫" NOR, HIB "�Ƿ��켫" NOR, HIY "�Ƿ��켫" NOR,
        HIW "������˫" NOR, HIB "������˫" NOR, HIY "������˫" NOR,
        HIW "һ���콾" NOR, HIB "һ���콾" NOR, HIY "һ���콾" NOR,
        HIW "�������" NOR, HIB "�������" NOR, HIY "�������" NOR,
        HIW "��������" NOR, HIB "��������" NOR, HIY "��������" NOR,
        HIW "��������" NOR, HIB "��������" NOR, HIY "��������" NOR,
        HIW "������" NOR, HIB "������" NOR, HIY "������" NOR,
        HIW "��ǰ����" NOR, HIB "��ǰ����" NOR, HIY "��ǰ����" NOR,
        HIW "��ɲ�" NOR, HIB "��ɲ�" NOR, HIY "��ɲ�" NOR,
        HIW "�����û" NOR, HIB "�����û" NOR, HIY "�����û" NOR,
        HIW "������ʥ" NOR, HIB "������ʥ" NOR, HIY "������ʥ" NOR,
        HIW "��豹���" NOR, HIB "��豹���" NOR, HIY "��豹���" NOR,
        HIW "���˺�һ" NOR, HIB "���˺�һ" NOR, HIY "���˺�һ" NOR,
        HIW "��������" NOR, HIB "��������" NOR, HIY "��������" NOR,
        HIW "ƽ������" NOR, HIB "ƽ������" NOR, HIY "ƽ������" NOR,
});

mapping mpTimeRank = ([
	1 : ({ 8, "��������" }),
	2 : ({ 10, "��������" }),
	3 : ({ 12, "��������" }),
	4 : ({ 14, "��������" }),
	5 : ({ 16, "��������" }),
	6 : ({ 18, "�м�����" }),
	7 : ({ 20, "��������" }),
	8 : ({ 22, "�м�����" }),
	9 : ({ 24, "�м�����" }),
	10 : ({ 26, "�м�����" }),
	11 : ({ 28, "�м�����" }),
	12 : ({ 30, "�м�����" }),
	13 : ({ 32, "�м�����" }),
	14 : ({ 34, "�м�����" }),
	15 : ({ 36, "�м�����" }),
	16 : ({ 38, "�߼�����" }),
	17 : ({ 40, "�м�����" }),
	18 : ({ 42, "�߼�����" }),
	19 : ({ 44, "�м�����" }),
	20 : ({ 46, "�߼�����" }),
	21 : ({ 48, "�м�����" }),
	22 : ({ 50, "�߼�����" }),
	23 : ({ 52, "�߼�����" }),
	24 : ({ 54, "�߼�����" }),
	25 : ({ 56, "�߼�����" }),
	26 : ({ 58, "�߼�����" }),
	27 : ({ 60, "�ؼ�����" }),
	28 : ({ 62, "�߼�����" }),
	29 : ({ 64, "�ؼ�����" }),
	30 : ({ 66, "�߼�����" }),
	31 : ({ 68, "�ؼ�����" }),
	32 : ({ 70, "�ؼ�����" }),
	33 : ({ 72, "�ؼ�����" }),
	34 : ({ 74, "�߼�����" }),
	35 : ({ 76, "�ؼ�����" }),
	36 : ({ 78, "�ؼ�����" }),
	37 : ({ 80, "�ؼ�����" }),
	38 : ({ 82, "�ؼ�����" }),
	39 : ({ 84, "�߼�����" }),
	40 : ({ 86, "�ؼ�����" }),
	41 : ({ 88, "�ؼ�����" }),
	42 : ({ 90, "�ؼ�����" }),
	43 : ({ 92, "�ؼ�����" }),
	44 : ({ 94, "�ؼ�����" }),
	45 : ({ 96, "�ؼ�����" }),
	46 : ({ 98, "�ؼ�����" }),
	47 : ({ 100, "�ؼ�����" }),
	48 : ({ 102, "�ؼ�����" }),
	49 : ({ 104, "�ؼ�����" }),
	50 : ({ 106, "�ؼ�����" }),
	51 : ({ 108, "�ؼ�����" }),
	52 : ({ 110, "�ؼ�����" }),
	53 : ({ 112, "�ؼ�����" }),
	54 : ({ 114, "�ؼ�����" }),
	55 : ({ 116, "�ؼ�����" }),
	56 : ({ 118, "�ؼ�����" }),
	57 : ({ 120, "�ؼ�����" }),
	58 : ({ 122, "�ؼ�����" }),
	59 : ({ 124, "�ؼ�����" }),
	60 : ({ 126, "�ؼ�����" }),
	61 : ({ 128, "�ؼ�����" }),
	62 : ({ 130, "�ؼ�����" }),
	63 : ({ 132, "�ؼ�����" }),
	64 : ({ 134, "�ؼ�����" }),
	65 : ({ 136, "�ؼ�����" }),
	66 : ({ 138, "�ؼ�����" }),
	67 : ({ 140, "�ؼ�����" }),
	68 : ({ 142, "�ؼ�����" }),
	69 : ({ 144, "�ؼ�����" }),
	70 : ({ 146, "�ؼ�����" }),
	71 : ({ 148, "�ؼ�����" }),
	72 : ({ 150, "�ؼ�����" }),
	73 : ({ 152, "�ؼ�����" }),
	74 : ({ 154, "�ؼ�����" }),
	75 : ({ 156, "�ؼ�����" }),
	76 : ({ 158, "�ؼ�����" }),
	77 : ({ 160, "�ؼ�����" }),
	78 : ({ 162, "�ؼ�����" }),
	79 : ({ 164, "�ؼ�����" }),
	80 : ({ 166, "�ؼ�����" }),
	81 : ({ 168, "�ؼ�����" }),

]);
int sizeof_rank = sizeof(RankTable);
string *nFamily = ({"�һ�Դ","��ɽ","������","����","éɽ","����ɽ","������"});

// ���������������ν
string get_rank( object who )
{
        int ap, cp;

        if( !objectp(who) ) return "";

        ap = who->get_ap();
        cp = who->get_cp();
        if( cp > ap ) ap = cp;

        ap = range_value( ap / 30, 0, sizeof_rank - 1 );

        return RankTable[ap];
}

//����ʱ���ȡ��Ϊ�ȼ�
int check_online_level(int hour)
{
	int i,size,*nTmp,level,count;
	mixed *mxTmp;
	
	nTmp = sort_array(keys(mpTimeRank),1);	//����
	for(i=0,size=sizeof(nTmp);i<size;i++)
	{
		level = nTmp[i];
		mxTmp = mpTimeRank[level];
		count += mxTmp[0];
		if ( count < hour )
			continue;
		if ( count == hour )
			break;
		level --;
		break;
	}
	return level;
}
//
void send_friend_info(object me,int level)
{
        object who;
        mapping Friends;
        string *key,acount,cTmp;
        int i, size,id;

	Friends = me->get_friend_dbase();
        size = sizeof( key = keys(Friends) );
        if( size ) key = sort_array(key, 1);
        cTmp = sprintf(BLK "������\n    ��˵%s��ҵ���Ϊ�ֽ�һ�����Ѿ��ﵽ��%d������λ����ף�����ɣ�",me->get_name(),level);
        for( i = 0; i < size; i ++ )
        {
        	id = to_int(key[i]);
                acount = me->get_friend_id(id);
		MAILBOX->sys_mail(acount,id,cTmp);
        }
}
//��Ϊϵͳ
void online_rank(object who,int flag)
{
	int i,level,hour,level1;
	
	if ( "sys/sys/count"->get_new_story() == 0 )
		return ;
	if ( flag == 0 )
	{
		if ( !who->get_save_2("online_rank.time") )	//��ʼ��
		{
			who->set_save_2("online_rank.time",who->get_game_time());
			hour = who->get_game_time()/3600;
			level = check_online_level(hour);
			who->set_save_2("online_rank.level",level);
			USER_ENERGY_D->count_max_hp(who);
		}
		else if ( who->get_save_2("online_rank.time") < who->get_game_time() )	//У��ʱ��
		{
			who->set_save_2("online_rank.time",who->get_game_time());
		}
		else if ( who->get_save_2("online_rank.time") > who->get_game_time() )	//У��ʱ��
		{
			who->set_game_time(who->get_save_2("online_rank.time"));
		}
		who->set_save_2("online_rank.start",time());
		
		return ;
	}
	else if ( flag == 1 )
	{
		i = who->get_save_2("online_rank.start");
		if ( !i )
		{
			who->set_save_2("online_rank.start",time());
			return ;
		}
		i = gone_time(i);
		hour = who->add_save_2("online_rank.time",i)/3600;
		who->set_save_2("online_rank.start",time());
		level = who->get_save_2("online_rank.level");
		level1 = check_online_level(hour);
		if ( level >= level1 )
			return ;
		//��Ϊ����
		who->set_save_2("online_rank.level",level1);
		send_user(who,"%c%c%c",0xA2,10,level1);
		USER_ENERGY_D->count_max_hp(who);
		MAILBOX->sys_mail(who->get_id(),who->get_number(),BLK"������\n    	��ϲ�������ֽ�һ�㣬���Ѿ�Ϊ��Ԥ�����������Ϊ��������´ι���Ϊ֮ǰ���㶼�������ܹ�������ȡ�����Ϊ���");
		if ( (level1 % 27) == 0 )
			send_friend_info(who,level1);
	}
		
}
//
varargs int give_item(object who, string cName,int color,int level)
{
	int p;
	object item;
	
	item = new(cName);
	if ( !item )
		return 0;
	p = item->move(who,-1);
	if ( !p )
	{
		send_user(who,"%c%s",'!',"�����ϵ�������λ����");
		destruct(item);
		return 0;
	}
	if ( color == 1 )
		ITEM_EQUIP_D->init_equip_prop_1(item);
	else if ( color == 3 )
		ITEM_EQUIP_D->init_equip_prop_3(item);

	if ( level )
		item->set_level(level);
	item->add_to_user(p);
	send_user(who,"%c%s",';',sprintf("��ȡ����ɹ�����õ�"HIR"%s",item->get_name()));
	return 1;
}
//��������
int get_bonus1(object who)
{
	int ret,exp;

	if ( random(2) )
	{
		switch(random(4))
		{
		default:
		case 0:
			ret = give_item(who,"/item/std/6002",0);	//Ǭ����
			break;
		case 1:
			ret = give_item(who,"item/08/0013",0);		//�󶨵�ս����
			break;
		case 2:
			ret = give_item(who,BOOK_FILE->get_book_file(),0);	//������׼�����
			break;
		case 3:
			ret = give_item(who,COLLECT_FILE->get_collect_file(),0);	//����ղ�Ʒ
			break;
		}
		
	}
	else
	{
		switch(random(6))
		{
		default:
		case 0:
			ret = give_item(who,"/item/final/15/1504",0);	//��������
			break;
		case 1:
			ret = give_item(who,"/item/final/15/1502",0);		//�����﹥
			break;
		case 2:
			exp = 100000;
			ret = 1;
			break;
		case 3:
			exp = 80000;
			ret = 1;
			break;
		case 4:
			exp = 60000;
			ret = 1;
			break;			
		case 5:
			ret = give_item(who,"item/44/4404",0);	//����Һ
			break;
		}		
		
	}
	if ( exp )
	{
		who->add_exp(exp);
		send_user(who,"%c%s",';',sprintf("��ȡ����ɹ�����õ�%d����",exp));
	}
	return ret;
}
//�м�����
int get_bonus2(object who)
{
	int ret,exp;
        string *nTmp,tmp;

	if ( random(2) )
	{
		switch(random(5))
		{
		default:
		case 0:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,50,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//50�������ɫװ��
			break;
		case 1:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,60,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//60�������ɫװ��
			break;
		case 2:
			ret = give_item(who,"quest/product2"->get_random_level_product(50,50));	//50�������ɫͼֽ
			break;
		case 3:
			ret = give_item(who,"quest/product2"->get_random_level_product(60,60));	//60�������ɫͼֽ
			break;
		case 4:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,50,WAIST_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,3);	//50�������ɫ����
			break;
		}
	}
	else
	{
		switch(random(14))
		{
		default:
		case 0:
			//����߼�ҩƷ
			switch(random(9))
			{
			default:
			case 0:
				ret = give_item(who,"item/91/9125");
				break;	
			case 1:
				ret = give_item(who,"item/91/9150");
				break;
			case 2:
				ret = give_item(who,"item/91/9160");
				break;
			case 3:
				ret = give_item(who,"item/91/9161");
				break;
			case 4:
				ret = give_item(who,"item/91/9162");
				break;	
			case 5:
				ret = give_item(who,"item/91/9163");
				break;
			case 6:
				ret = give_item(who,"item/91/9164");
				break;
			case 7:
				ret = give_item(who,"item/91/9165");
				break;
			case 8:
				ret = give_item(who,"item/std/0088");
				break;
				
			}
			break;
		case 1:
			ret = give_item(who,STONE_FILE->get_diamond_file(),0,1);	//1����ʯ
			break;
		case 2:
			ret = give_item(who,"item/44/4488");	//�������＼�ܵ�
			break;	
		case 3:
			ret = give_item(who,sprintf("item/std/%d",8001+random(4)));	//�����ȱ�ر�ͼ
			break;	
		case 4:
			ret = give_item(who,"item/91/9167");	//�ϲε�
			break;	
		case 5:
			ret = give_item(who,"item/44/4404",0);	//����Һ
			break;
		case 6:
			ret = give_item(who,"/item/final/15/1504",0);	//��������
			break;
		case 7:
			ret = give_item(who,"/item/final/15/1502",0);		//�����﹥
			break;
		case 8:
			exp = 200000;
			ret = 1;
			break;
		case 9:
			exp = 250000;
			ret = 1;
			break;
		case 10:
			exp = 300000;
			ret = 1;
			break;			
		case 11:
			ret = give_item(who,"item/08/0013",0);		//�󶨵�ս����
			break;
		case 12:
			ret = give_item(who,"item/91/9178",0);		//������
			break;
		case 13:
			ret = give_item(who,"item/sell/0044",0);	//��������
			break;
		}		
	}
	if ( exp )
	{
		who->add_exp(exp);
		send_user(who,"%c%s",';',sprintf("��ȡ����ɹ�����õ�%d����",exp));
	}
	return ret;
}
//�߼�����
int get_bonus3(object who)
{
	int ret,exp;
        string *nTmp,tmp;
	if ( random(2) )
	{
		switch(random(13))
		{
		default:
		case 0:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,70,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//70����ɫװ��
			break;
		case 1:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,80,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//80�������ɫװ��
			break;
		case 2:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,90,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//90�������ɫװ��
			break;
		case 3:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,70,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//70�������ɫ����
			break;
		case 4:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,80,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//80�������ɫ����
			break;
		case 5:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,70,HEAD_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,3);	//70�������ɫñ��
			break;
		case 6:
			ret = give_item(who,"quest/product2"->get_random_level_product(70,70));	//70�������ɫװ��ͼֽ
			break;
		case 7:
			ret = give_item(who,"quest/product2"->get_random_level_product(80,80));	//80�������ɫͼֽ
			break;
		case 8:
			ret = give_item(who,"quest/product2"->get_random_level_product(90,90));	//90�������ɫͼֽ
			break;
		case 9:
			ret = give_item(who,"/item/std/6002",0);	//Ǭ����
			break;
		case 10:
			ret = give_item(who,"item/08/0013",0);		//�󶨵�ս����
			break;
		case 11:
			ret = give_item(who,BOOK_FILE->get_book_file(),0);	//������׼�����
			break;
		case 12:
			ret = give_item(who,COLLECT_FILE->get_collect_file(),0);	//����ղ�Ʒ
			break;
		}
	}
	else
	{
		switch(random(15))
		{
		default:
		case 0:
			//����߼�ҩƷ
			switch(random(9))
			{
			default:
			case 0:
				ret = give_item(who,"item/91/9125");
				break;	
			case 1:
				ret = give_item(who,"item/91/9150");
				break;
			case 2:
				ret = give_item(who,"item/91/9160");
				break;
			case 3:
				ret = give_item(who,"item/91/9161");
				break;
			case 4:
				ret = give_item(who,"item/91/9162");
				break;	
			case 5:
				ret = give_item(who,"item/91/9163");
				break;
			case 6:
				ret = give_item(who,"item/91/9164");
				break;
			case 7:
				ret = give_item(who,"item/91/9165");
				break;
			case 8:
				ret = give_item(who,"item/std/0088");
				break;
				
			}
			break;
			break;
		case 1:
			ret = give_item(who,STONE_FILE->get_diamond_file(),0,1);	//1����ʯ
			break;
		case 2:
			ret = give_item(who,"item/44/4488");	//�������＼�ܵ�
			break;	
		case 3:
			ret = give_item(who,sprintf("item/std/%d",8001+random(4)));	//�����ȱ�ر�ͼ
			break;	
		case 4:
			ret = give_item(who,"item/91/9167");	//�ϲε�
			break;	
		case 5:
			ret = give_item(who,"item/44/4404",0);	//����Һ
			break;
		case 6:
			ret = give_item(who,"/item/final/15/1504",0);	//��������
			break;
		case 7:
			ret = give_item(who,"/item/final/15/1502",0);		//�����﹥
			break;
		case 8:
			exp = 600000;
			ret = 1;
			break;
		case 9:
			exp = 700000;
			ret = 1;
			break;
		case 10:
			exp = 800000;
			ret = 1;
			break;			
		case 11:
			ret = give_item(who,"item/08/0013",0);		//�󶨵�ս����
			break;
		case 12:
			ret = give_item(who,"item/91/9178",0);		//������
			break;
		case 13:
			ret = give_item(who,"item/sell/0044",0);	//��������
			break;
		case 14:
			ret = give_item(who,sprintf("item/sell/%04d",15+random(5)),0);//ϴ����
			break;
		}		
	}
	if ( exp )
	{
		who->add_exp(exp);
		send_user(who,"%c%s",';',sprintf("��ȡ����ɹ�����õ�%d����",exp));
	}
	return ret;
}
//�ؼ�����
int get_bonus4(object who)
{
	int ret,exp;
        string *nTmp,tmp;

	if ( random(2) )
	{
		switch(random(14))
		{
		default:
		case 0:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,100,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//100����ɫװ��
			break;
		case 1:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,110,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//110�������ɫװ��
			break;
		case 2:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,120,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//120�������ɫװ��
			break;
		case 3:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,100,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//100�������ɫ����
			break;
		case 4:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,110,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//110�������ɫ����
			break;
		case 5:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,100,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,3);	//100�������ɫ����
			break;
		case 6:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,110,BOOTS_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,3);	//110�������ɫЬ��
			break;
		case 7:
			ret = give_item(who,"quest/product2"->get_random_level_product(100,100));	//100�������ɫװ��ͼֽ
			break;
		case 8:
			ret = give_item(who,"quest/product2"->get_random_level_product(110,110));	//110�������ɫͼֽ
			break;
		case 9:
			ret = give_item(who,"quest/product2"->get_random_level_product(120,120));	//120�������ɫͼֽ
			break;
		case 10:
			ret = give_item(who,"/item/std/6002",0);	//Ǭ����
			break;
		case 11:
			ret = give_item(who,"item/08/0013",0);		//�󶨵�ս����
			break;
		case 12:
			ret = give_item(who,BOOK_FILE->get_book_file(),0);	//������׼�����
			break;
		case 13:
			ret = give_item(who,COLLECT_FILE->get_collect_file(),0);	//����ղ�Ʒ
			break;
		}
	}
	else
	{
		switch(random(15))
		{
		default:
		case 0:
			//����߼�ҩƷ
			switch(random(9))
			{
			default:
			case 0:
				ret = give_item(who,"item/91/9125");
				break;	
			case 1:
				ret = give_item(who,"item/91/9150");
				break;
			case 2:
				ret = give_item(who,"item/91/9160");
				break;
			case 3:
				ret = give_item(who,"item/91/9161");
				break;
			case 4:
				ret = give_item(who,"item/91/9162");
				break;	
			case 5:
				ret = give_item(who,"item/91/9163");
				break;
			case 6:
				ret = give_item(who,"item/91/9164");
				break;
			case 7:
				ret = give_item(who,"item/91/9165");
				break;
			case 8:
				ret = give_item(who,"item/std/0088");
				break;
			}
			break;
			break;
		case 1:
			ret = give_item(who,STONE_FILE->get_diamond_file(),0,1);	//1����ʯ
			break;
		case 2:
			ret = give_item(who,"item/44/4488");	//�������＼�ܵ�
			break;	
		case 3:
			ret = give_item(who,sprintf("item/std/%d",8001+random(4)));	//�����ȱ�ر�ͼ
			break;	
		case 4:
			ret = give_item(who,"item/91/9167");	//�ϲε�
			break;	
		case 5:
			ret = give_item(who,"item/44/4404",0);	//����Һ
			break;
		case 6:
			ret = give_item(who,"/item/final/15/1504",0);	//��������
			break;
		case 7:
			ret = give_item(who,"/item/final/15/1502",0);		//�����﹥
			break;
		case 8:
			exp = 1000000;
			ret = 1;
			break;
		case 9:
			exp = 1100000;
			ret = 1;
			break;
		case 10:
			exp = 1200000;
			ret = 1;
			break;			
		case 11:
			ret = give_item(who,"item/08/0013",0);		//�󶨵�ս����
			break;
		case 12:
			ret = give_item(who,"item/91/9178",0);		//������
			break;
		case 13:
			ret = give_item(who,"item/sell/0044",0);	//��������
			break;
		case 14:
			ret = give_item(who,sprintf("item/sell/%04d",15+random(5)),0);//ϴ����
			break;
		}		
	}
	if ( exp )
	{
		who->add_exp(exp);
		send_user(who,"%c%s",';',sprintf("��ȡ����ɹ�����õ�%d����",exp));
	}
	return ret;
}
//��ȡ��Ϊ����
void get_rank_bonus(object who,object me)
{
	int level,ret;
	string cTmp;
	
	level = who->get_save_2("online_rank.level");
	if ( !level )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s��\n    �㻹û����Ϊ�ȼ���\n"ESC"�뿪", me->get_name(), ) );
		return ;	
	}	
	if ( level == who->get_save_2("online_rank.bonus") )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s��\n    ���Ѿ���������ˣ�\n"ESC"�뿪", me->get_name(), ) );
		return ;	
	}
	cTmp = mpTimeRank[level][1];
	switch(cTmp)
	{
	default:
	case "��������":
		ret = get_bonus1(who);
		break;	
	case "�м�����":
		ret = get_bonus2(who);
		break;	
	case "�߼�����":
		ret = get_bonus3(who);
		break;
	case "�ؼ�����":
		ret = get_bonus4(who);
		break;	
	}
	if ( !ret )
		return ;
	who->set_save_2("online_rank.bonus",level);
}
//��ȡ�Ѻù�ϵ
string get_friend_desc(int i )
{
	string result;
	if ( i > 5000 )
		result = "����֮��";
	else if ( i > 3500 )
		result = "��ͬ����";
	else if ( i > 1800 )
		result = "��������";
	else if ( i > 800 )
		result = "����֪��";
	else if ( i > 200 )
		result = "Ƽˮ���";
	else 
		result = "��ͨ����";	
	return result;	
}
