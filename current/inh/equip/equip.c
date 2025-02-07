
#include <ansi.h>
#include <item.h>
#include <equip.h>

private static int Color;               // ��Ʒ���  1 ��װ 2 ��װ 3 ��װ 4 ��װ

private int ItemLevel;                  // ��Ʒ�ȼ�
private string MakeProp;                // �ϳɼ�¼

private int Lasting;                    // �;ö�
private int MaxLasting;                 // ����;ö�

private int iHide = 1;			// 1 δ���� 0 �Ѽ���

private static object Owner;            // �û���ʶ

private int iBind;			// 0 �ް� 1 װ����� 2 װ�����Ѱ� 3 ��ð� 4 ����Ѱ�

// ��������װ����Ʒ
int is_equip() { return 1; }

// ��������װ����Ʒ
int get_item_type() { return ITEM_TYPE_EQUIP; }

// ��������װ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_EQUIP; }

string set_name( string name );
int get_level();

// -------------------------------------------------------------

// ���������ú���
void setup() { Lasting = MaxLasting; }

// ��������ȡװ�����
int get_item_color() { return Color; }

// ����������װ�����
int set_item_color( int type ) { return Color = type; }

// ��������ȡ���¼�ֵ
int get_bonus_value() 
{ 
        switch( get_level() )
        {
      case 60 : return 1500;
      case 70 : return 2500;
      default : return 0;
        }
}

// -------------------------------------------------------------

// ��������ȡ�ȼ�����
int get_item_level() { return ItemLevel; }

// ���������õȼ�����
int set_item_level( int level ) 
{ 
        string file = get_file_name( this_object() );
        if( level < 1 ) 
                set_name( file->get_name() );
        else    set_name( sprintf( "%s%+d", file->get_name(), level ) );

        return ItemLevel = level; 
}

// ����������ȼ�����
int add_item_level( int level ) { return set_item_level( ItemLevel + level ); }

// ��������ȡ�ϳɼ�¼
string get_make_prop() { return MakeProp ? MakeProp : ""; }

// ���������úϳɼ�¼
string set_make_prop( string prop ) { return MakeProp = prop; }

// -------------------------------------------------------------

// ��������ȡ�;ö�
int get_lasting() { return Lasting; }

// �����������;ö�
int set_lasting( int time )
{
        object who;

        time = range_value(time, 0, MaxLasting);

        if(     Lasting / 10 != time / 10
        &&    ( objectp( who = Owner ) || objectp( who = environment() ) ) )
        {
                Lasting = time;  USER_INVENTORY_D->send_lasting_tips(who);
                send_user( who, "%c%d%c", 0x31, getoid( this_object() ), 0 );    // ��������
        }
        if(    Lasting<100
        &&      objectp( who = Owner ) ) 
        {
                Lasting = 0;  USER_EQUIP_D->count_equip_apply( who, this_object() );
                if( this_object()->get_equip_type() == WEAPON_TYPE )
                        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w", 0x7c, getoid(who), UNARMED );
        }
        return Lasting = time;
}

// �����������;ö�
int add_lasting( int time ) { return set_lasting( Lasting + time ); }

// ��������ȡ����;ö�
int get_max_lasting() { return MaxLasting; }

// ��������������;ö�
int set_max_lasting( int time ) 
{ 
        object who;

        if( time < 1 ) time = 0;
        if( MaxLasting / 100 != time / 100 )    // ��������
        {
                if( objectp( who = Owner ) || objectp( who = environment() ) )
                        send_user( who, "%c%d%c", 0x31, getoid( this_object() ), 0 );
        }
        if( time < Lasting ) set_lasting(time);
        return MaxLasting = time; 
}

// ��������������;ö�
int add_max_lasting( int time ) { set_max_lasting( MaxLasting + time ); }

// -------------------------------------------------------------

// ��������ȡ�û���ʶ
object get_owner() { return Owner; }

// �����������û���ʶ
object set_owner( object who ) { return Owner = who; }

// �������������ȡ��
int remove_from_user()
{
        object who;

        if( ( who = environment() ) && userp(who) ) 
        {
                send_user( who, "%c%d", 0x2d, getoid( this_object() ) );
                return 1;
        }
        else if( objectp(Owner) && userp(Owner) )
        {
                send_user( Owner, "%c%d", 0x2d, getoid( this_object() ) );
                return 1;
        }
        else    return 0;
}

// ��������ȡ������־
int get_hide() { return iHide; }

// ���������ü�����־
int set_hide( int time ) 
{ 
        object who;

        if( time < 1 ) time = 0;
        if( iHide != time )    // ��������
        {
                if( objectp( who = Owner ) || objectp( who = environment() ) )
                        send_user( who, "%c%d%c", 0x31, getoid( this_object() ), 0 );
        }
        return iHide = time; 
}

// ��������ȡ�󶨱�־
int get_bind() { return iBind; }

// ���������ð󶨱�־
int set_bind(int flag) { return iBind = flag; }