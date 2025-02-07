
#include <ansi.h>
#include <equip.h>
#include <effect.h>

private static object *Equip = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0 });    // װ�����飺ͷ�������֡��������š�����

private static int * armor_code = ({  20000, 20100, 30000, 30100, 40000, 40100, 50000, 50100, 80000, 80100, 60000, 60100, 70000, 70100, 10000, 10100, 10200, 10300 });

int get_login_flag();

// -------------------------------------------------------------

// ��������ȡװ������
object *get_all_equip() { return copy(Equip); }

// ��������ȡװ������
object get_equip( int index ) 
{ 
        switch( index )
        {
         case HEAD_TYPE : return Equip[HEAD_POSITION];
         case NECK_TYPE : return Equip[NECK_POSITION];
       case WEAPON_TYPE : return Equip[WEAPON_POSITION];
        case ARMOR_TYPE : return Equip[ARMOR_POSITION];
        case WAIST_TYPE : return Equip[WAIST_POSITION];
        case BOOTS_TYPE : return Equip[BOOTS_POSITION];
         case HAND_TYPE : return Equip[HAND_POSITION];
       case FAMILY_TYPE : return Equip[FAMILY_POSITION];
         case BACK_TYPE : return Equip[BACK_POSITION];
                default : return 0;
        }
}

// ��������ȡװ������
object set_equip( int index, object item ) 
{ 
        switch( index )
        {
         case HEAD_TYPE : return Equip[HEAD_POSITION] = item;
         case NECK_TYPE : return Equip[NECK_POSITION] = item;
       case WEAPON_TYPE : return Equip[WEAPON_POSITION] = item;
        case ARMOR_TYPE : return Equip[ARMOR_POSITION] = item;
        case WAIST_TYPE : return Equip[WAIST_POSITION] = item;
        case BOOTS_TYPE : return Equip[BOOTS_POSITION] = item;
         case HAND_TYPE : return Equip[HAND_POSITION] = item;
       case FAMILY_TYPE : return Equip[FAMILY_POSITION] = item;
         case BACK_TYPE : return Equip[BACK_POSITION] = item;
                default : return 0;
        }
}

// ����������װ������
int use_equip( object equip ) { return USER_EQUIP_D->use_equip( this_object(), equip ); }

// ��������ȡװ������(���� inventory.c)
int restore_equip( object equip ) { return USER_EQUIP_D->restore_equip( this_object(), equip ); }

// �������Ƴ�װ������
int remove_equip( int index ) { return USER_EQUIP_D->remove_equip( this_object(), index ); }

// ����������װ������(���� perform ��, ����Ҳ�õ�)
int drop_equip( int index ) { return USER_EQUIP_D->drop_equip( this_object(), index ); }

// -------------------------------------------------------------

int get_gender();

// ��������ȡ���Ŵ���
int get_armor_code()
{
	object me = this_object();
	int family, gender, level, i, size;
	int suits, armor;		
	armor = 0;
        if( get_effect(me, EFFECT_MAGIC_4243) )
        {
        	armor = me->get_save("pf#4243");
        }
        else
        if ( get_effect(me, EFFECT_MAGIC_CARD) )
        {
        	armor = me->get_save("magic_card");
        }
        else
        if (me->get_save("temp_act"))
        {
        	armor = me->get_save("temp_act");
        }
        else
        if (me->get("temp_act"))
        {
        	armor = me->get("temp_act");
        }
        if (armor>0) return armor;
	
//	if (MAIN_D->get_host_type()!=1000) return Code; 
	family = me->get_fam_type();
	if (family==0) family=8;
	if (family>8) family=8;
	gender = me->get_gender();
	family -= 1;
	gender-=1;
	if (gender<0||gender>1) gender=0;		
	
	armor = me->get_equip(ARMOR_TYPE);
	//��װ�·�,��ȡ��
//	if ( armor )
//	{
//		suits = armor->get_equip_serial();	
//	}
	if ("/sys/sys/count"->get_new_person())
	{
		gender = me->get_gender();
		family = me->get_fam_type();
		if (gender==1) gender = 0;
		else gender = 1000;
		if (family==8) family=0;
		family ++;
		return 10000+gender + family;
	}
		
	return armor_code[2*family+gender]+suits;
/*		
        if( objectp( Equip[ARMOR_POSITION] ) ) return Equip[ARMOR_POSITION]->get_armor_code();
//        if (MAIN_D->get_host_type()!=1000)
	if (0)
        	return get_gender() == 1 ? M_DUANGUA : F_DUANSHAN;
        else
        	return get_gender() == 1 ? 10000 : 10100;
*/        	
}

// ��������ȡ������ɫ
int get_armor_color_1() { return objectp( Equip[ARMOR_POSITION] ) ? Equip[ARMOR_POSITION]->get_armor_color_1() : 0x42084208; }

// ��������ȡ������ɫ
int get_armor_color_2() { return objectp( Equip[ARMOR_POSITION] ) ? Equip[ARMOR_POSITION]->get_armor_color_2() : 0x42084208; }

// ��������ȡñ�Ӵ���
int get_head_code()
{
        if( objectp( Equip[HEAD_POSITION] ) ) return Equip[HEAD_POSITION]->get_head_code();
        else return get_gender() == 1 ? M_BANGDAI : F_BANGDAI;
}

// ��������ȡñ����ɫ
int get_head_color() { return objectp( Equip[HEAD_POSITION] ) ? Equip[HEAD_POSITION]->get_head_color() : 0x42084208; }

// ��������ȡ��������
int get_weapon_code()
{
        if( objectp( Equip[WEAPON_POSITION] ) )
        {
                if( Equip[WEAPON_POSITION]->get_lasting() < 100 ) return UNARMED;
                if (get_effect(this_object(), EFFECT_NO_WEAPON)) return UNARMED;                       
                return Equip[WEAPON_POSITION]->get_weapon_type();
        }
        else    return UNARMED;
}

// ��������ȡ�������룯����
int get_weapon_code_2()
{
	int level, color, type;
        if( objectp( Equip[WEAPON_POSITION] ) )
        {
                if( Equip[WEAPON_POSITION]->get_lasting() < 100 ) return UNARMED;
                level = Equip[WEAPON_POSITION]->get_weapon_level();
                color = Equip[WEAPON_POSITION]->get_item_color();
                type = Equip[WEAPON_POSITION]->get_weapon_type();
                if (level==0)
                {
                	level = Equip[WEAPON_POSITION]->get_level();
                	level /= 10;
                	if (level>14) level = 14;
                }
                if (color==2)
                {
                	if (Equip[WEAPON_POSITION]->get_level()<80) level = 12;
                	else level = 13;
                }
                else
                if (color==3) level = 14;   
                else
                if (color==0 && level >= 10) level = 9;             
                return  type | (  level << 8 );
        }
        else    return UNARMED;
}

// ��������ȡ������ɫ
int get_weapon_color()
{
	int level, color;
        if( objectp( Equip[WEAPON_POSITION] ) )
        {          
                return Equip[WEAPON_POSITION]->get_weapon_color();
        }
        else    return 0;
}

// ��������ȡ�����ȼ���ֵ����Ӧ����ɫ����ûд��
int get_weapon_color_2()
{
	int level, color, ret;
        if( objectp( Equip[WEAPON_POSITION] ) )
        {
                if( Equip[WEAPON_POSITION]->get_lasting() < 100 ) return 0;
                color = Equip[WEAPON_POSITION]->get_item_color();
                if (color==0||color==4) return 0;
                level = Equip[WEAPON_POSITION]->get_level();
                switch(color)
                {
                case 1:
                	if (level<=50) ret = 0xffff;
                	else
                	if (level<=70) ret = 0xbdc;
                	else
                		ret = 0x1a56;
                	break;
                case 2:
                	if (level<=50) ret = 0x4fed;
                	else
                	if (level<=70) ret = 0x4d0;
                	else
                		ret = 0xfc62;
                	break;
                case 3:
                default:
                	if (level<=50) ret = 0x831d;
                	else
                	if (level<=70) ret = 0x4898;
                	else
                		ret = 0x680d;
                	break;                	                	
                }
                return ret;
        }
        else    return 0;
}

int get_back() 
{
	if( objectp( Equip[BACK_POSITION] ) )
	{
		return Equip[BACK_POSITION]->get_back_type();
	}
	else
		return 0;
}

int get_back_color() 
{
	if( objectp( Equip[BACK_POSITION] ) )
	{
		return Equip[BACK_POSITION]->get_back_color();
	}
	else
		return 0;
}

int get_back2() 
{
	if( objectp( Equip[BACK_POSITION] ) )
	{
		return Equip[BACK_POSITION]->get_back2_type();
	}
	else
		return 0;
}

int get_back2_color() 
{
	if( objectp( Equip[BACK_POSITION] ) )
	{
		return Equip[BACK_POSITION]->get_back2_color();
	}
	else
		return 0;
}