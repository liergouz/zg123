
#include <ansi.h>

inherit DBASE_F;
inherit SAVE_F;

private int Level;                      // �ȼ�

private int Defence;                    // �Ƿ�
private int Soldier;                    // ʿ��
private int Armor;                      // װ��
private int Training;                   // ѵ����

private int Cash;                       // �ʽ�(�����ʽ�)
private int Money;                      // �����ʽ�
private int Tax;                        // ˰��
private int Tax2;                       // ��������
private int Food;                       // ����

private int Stability;                  // ����
private int Disease;                    // ����

private int Agriculture;                // ũҵ
private int Fishculture;                // ��ҵ
private int Mining;                     // ��ҵ
private int Industry;                   // ��ҵ
private int Commercial;                 // ��ҵ

private int Arts;                       // ����
private int Education;                  // ����
private int Religion;                   // �ڽ�

private string Master;                  // ����
private string Master2;                 // ������(������)
private string Master3;                 // ������(������)

private string MasterName;              // ��������
private string MasterName2;             // ����������
private string MasterName3;             // ����������

private int BuyTax;                     // ����˰
private int SellTax;                    // ����˰
private int BuyTax2;                    // ����˰��
private int SellTax2;                   // ����˰��

private int Tax2Cash;                   // ˰�շֺ���

private int *Friend = ({ 0, 0, 0, 0, 0, 0, 0 });        // �Ѻö�
private int *Relation = ({ 0, 0, 0, 0, 0, 0, 0 });      // �⽻��ϵ

private int Contribute;                 // ���չ���

private int *Salary0 = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, });    // ����/���ʱ�(Դ)
private int *Salary2 = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, });    // ��ȡ���ʱ�

// ����������ʶ����
int is_city() { return 1; }

// -------------------------------------------------------------

// ��������ȡ�ȼ�����
int get_level() { return Level; }

// ���������õȼ�����
int set_level( int point ) { return Level = point; }

// ����������ȼ�����
int add_level( int point ) { return set_level( Level + point ); }

// -------------------------------------------------------------

// ��������ȡ�Ƿ�����
int get_defence() { return Defence; }

// ���������óǷ�����
int set_defence( int point ) 
{ 
        if( point > Level * 2000 + 1000 ) point = Level * 2000 + 1000;
        return Defence = point; 
}

// ����������Ƿ�����
int add_defence( int point ) { return set_defence( Defence + point ); }

// �������ж�ʿ���㹻
int is_soldier_enough() { return Soldier >= Level * 50000 + 50000; }

// ��������ȡʿ������
int get_soldier() { return Soldier; }

// ����������ʿ������
int set_soldier( int point )
{ 
        if( point > Level * 50000 + 50000 ) point = Level * 50000 + 50000;
        if( point < Armor ) Armor = point;
        if( point < Training ) Training = point;
        return Soldier = point; 
}

// ����������ʿ������
int add_soldier( int point ) { return set_soldier( Soldier + point ); }

// ��������ȡװ������
int get_armor() { return Armor; }

// ����������װ������
int set_armor( int point ) 
{ 
        if( point > Soldier ) point = Soldier;
        return Armor = point; 
}

// ����������װ������
int add_armor( int point ) { return set_armor( Armor + point ); }

// ��������ȡѵ��������
int get_training() { return Training; }

// ����������ѵ��������
int set_training( int point ) 
{ 
        if( point > Soldier ) point = Soldier;
        return Training = point; 
}

// ����������ѵ��������
int add_training( int point ) { return set_training( Training + point ); }

// -------------------------------------------------------------

// ��������ȡ�����ʽ�
int get_cash() { return Cash; }

// ���������������ʽ�
int set_cash( int gold ) 
{ 
        if( gold > MAX_NUMBER ) gold = MAX_NUMBER;
        return Cash = gold; 
}

// ���������������ʽ�
int add_cash( int gold ) { return set_cash( Cash + gold ); }

// ��������ȡ�����ʽ�
int get_money() { return Money; }

// ���������û����ʽ�
int set_money( int gold ) 
{ 
        if( gold > MAX_NUMBER ) gold = MAX_NUMBER;
        return Money = gold; 
}

// ��������������ʽ�
int add_money( int gold ) { return set_money( Money + gold ); }

// ��������ȡ˰������
int get_tax() { return Tax; }

// ����������˰������
int set_tax( int gold ) 
{ 
        if( gold > MAX_NUMBER ) gold = MAX_NUMBER;
        return Tax = gold; 
}

// ����������˰������
int add_tax( int gold ) { return set_tax( Tax + gold ); }

// ��������ȡ��������
int get_tax_2() { return Tax2; }

// ������������������
int set_tax_2( int gold ) 
{ 
        if( gold > MAX_NUMBER ) gold = MAX_NUMBER;
        return Tax2 = gold; 
}

// ������������������
int add_tax_2( int gold ) { return set_tax_2( Tax2 + gold ); }

// ��������ȡ��������
int get_food() { return Food; }

// ������������������
int set_food( int point ) 
{ 
        if( point > MAX_NUMBER ) point = MAX_NUMBER;
        return Food = point; 
}

// ������������������
int add_food( int point ) { return set_food( Food + point ); }

// -------------------------------------------------------------

// ��������ȡ��������
int get_stability() { return Stability; }

// ���������ð�������
int set_stability( int point ) 
{ 
        if( point > 11000 ) point = 11000;
        return Stability = point; 
}

// ����������������
int add_stability( int point ) { return set_stability( Stability + point ); }

// ��������ȡ��������
int get_disease() { return Disease; }

// ���������ü�������
int set_disease( int point ) { return Disease = point; }

// ����������������
int add_disease( int point ) { return set_disease( Disease + point ); }

// -------------------------------------------------------------

// ��������ȡũҵ����
int get_agriculture() { return Agriculture; }

// ����������ũҵ����
int set_agriculture( int point ) 
{ 
        if( point > (Level + 1) * 20000 + 10000 ) point = (Level + 1) * 20000 + 10000;
        return Agriculture = point; 
}

// ����������ũҵ����
int add_agriculture( int point ) { return set_agriculture( Agriculture + point ); }

// ��������ȡ��ҵ����
int get_fishculture() { return Fishculture; }

// ������������ҵ����
int set_fishculture( int point ) 
{ 
        if( point > (Level + 1) * 20000 + 10000 ) point = (Level + 1) * 20000 + 10000;
        return Fishculture = point; 
}

// ������������ҵ����
int add_fishculture( int point ) { return set_fishculture( Fishculture + point ); }

// ��������ȡ��ҵ����
int get_mining() { return Mining; }

// ���������ÿ�ҵ����
int set_mining( int point ) 
{ 
        if( point > (Level + 1) * 20000 + 10000 ) point = (Level + 1) * 20000 + 10000;
        return Mining = point; 
}

// �����������ҵ����
int add_mining( int point ) { return set_mining( Mining + point ); }

// ��������ȡ��ҵ����
int get_industry() { return Industry; }

// ���������ù�ҵ����
int set_industry( int point ) 
{ 
        if( point > (Level + 1) * 20000 + 10000 ) point = (Level + 1) * 20000 + 10000;
        return Industry = point; 
}

// ����������ҵ����
int add_industry( int point ) { return set_industry( Industry + point ); }

// ��������ȡ��ҵ����
int get_commercial() { return Commercial; }

// ������������ҵ����
int set_commercial( int point ) 
{ 
        if( point > (Level + 1) * 20000 + 10000 ) point = (Level + 1) * 20000 + 10000;
        return Commercial = point; 
}

// ������������ҵ����
int add_commercial( int point ) { return set_commercial( Commercial + point ); }

// -------------------------------------------------------------

// ��������ȡ��������
int get_arts() { return Arts; }

// ������������������
int set_arts( int point ) 
{ 
        if( point > (Level + 1) * 20000 + 10000 ) point = (Level + 1) * 20000 + 10000;
        return Arts = point; 
}

// ������������������
int add_arts( int point ) { return set_arts( Arts + point ); }

// ��������ȡ��������
int get_education() { return Education; }

// ���������ý�������
int set_education( int point ) 
{ 
        if( point > (Level + 1) * 20000 + 10000 ) point = (Level + 1) * 20000 + 10000;
        return Education = point; 
}

// �����������������
int add_education( int point ) { return set_education( Education + point ); }

// ��������ȡ�ڽ�����
int get_religion() { return Religion; }

// �����������ڽ�����
int set_religion( int point ) 
{ 
        if( point > (Level + 1) * 20000 + 10000 ) point = (Level + 1) * 20000 + 10000;
        return Religion = point; 
}

// �����������ڽ�����
int add_religion( int point ) { return set_religion( Religion + point ); }

// -------------------------------------------------------------

// ��������ȡ�����ɣ�
string get_master() { return Master ? Master : ""; }

// ���������ó����ɣ�
string set_master( string id ) { return Master = id; }

// ��������ȡ�������ɣ�
string get_master_2() { return Master2 ? Master2 : ""; }

// ���������ó������ɣ�
string set_master_2( string id ) { return Master2 = id; }

// ��������ȡ�������ɣ�
string get_master_3() { return Master3 ? Master3 : ""; }

// ���������ó������ɣ�
string set_master_3( string id ) { return Master3 = id; }

// ��������ȡ��������
string get_master_name() { return MasterName ? MasterName : "����"; }

// ���������ó�������
string set_master_name( string name ) { return MasterName = name; }

// ��������ȡ����������
string get_master_name_2() { return MasterName2 ? MasterName2 : "����"; }

// ���������ó���������
string set_master_name_2( string name ) { return MasterName2 = name; }

// ��������ȡ����������
string get_master_name_3() { return MasterName3 ? MasterName3 : "����"; }

// ���������ó���������
string set_master_name_3( string name ) { return MasterName3 = name; }

// -------------------------------------------------------------

// ��������ȡ����˰
int get_buy_tax() { return BuyTax; }

// ��������������˰
int set_buy_tax( int tax ) { return BuyTax = range_value(tax, 1, 20); }

// ��������ȡ����˰
int get_sell_tax() { return SellTax; }

// ��������������˰
int set_sell_tax( int tax ) { return SellTax = range_value(tax, 1, 20); }

// ��������ȡ����˰��
int get_buy_tax_2() { return BuyTax2; }

// ��������������˰��
int set_buy_tax_2( int tax ) { return BuyTax2 = range_value(tax, 1, 20); }

// ��������ȡ����˰��
int get_sell_tax_2() { return SellTax2; }

// ��������������˰��
int set_sell_tax_2( int tax ) { return SellTax2 = range_value(tax, 1, 20); }

// ��������ȡ˰�շֺ���
int get_tax_2_cash() { return Tax2Cash; }

// ����������˰�շֺ���
int set_tax_2_cash( int tax ) { return Tax2Cash = range_value(tax, 40, 80); }

// -------------------------------------------------------------

// ��������ȡ�Ѻ�����
int *get_friend_dbase() { return copy(Friend); }

// ��������ʼ�Ѻ�����
int *init_friend_dbase() { return Friend = ({ 0, 0, 0, 0, 0, 0, 0 }); }

// ��������ȡ�⽻����
int *get_relation_dbase() { return copy(Relation); }

// ��������ʼ�⽻����
int *init_relation_dbase() { return Relation = ({ 0, 0, 0, 0, 0, 0, 0 }); }

// ��������ȡ�Ѻö�
int get_friend( int city ) 
{  
        if( city < 1 || city > 7 ) return 0;
        return Friend[city - 1];
}

// �����������Ѻö�
int set_friend( int city, int point ) 
{  
        if( city < 1 || city > 7 ) return 0;
        return Friend[city - 1] = range_value(point, -500, 500);
}

// �����������Ѻö�
int add_friend( int city, int point ) { return set_friend( city, get_friend(city) + point ); }

// ��������ȡ�⽻��ϵ
int get_relation( int city ) 
{  
        if( city < 1 || city > 7 ) return 0;
        return Relation[city - 1];
}

// ��������ȡ�⽻��ϵ
string get_relation_name( int city ) 
{  
        if( city < 1 || city > 7 ) return "����";

        switch( Relation[city - 1] )
        {
       case 2 : return "ͬ��";
       case 1 : return "�Ѻ�";
      default : return "����";
      case -1 : return "����";
      case -2 : return "ս��";
        }
}

// �����������⽻��ϵ
int set_relation( int city, int flag ) 
{  
        if( city < 1 || city > 7 ) return 0;
        return Relation[city - 1] = flag;
}

// -------------------------------------------------------------

// ��������ȡ���ʱ�����(Դ)
int *get_salary_dbase_0() { return copy(Salary0); }

// ��������ʼ���ʱ�����(Դ)
int *init_salary_dbase_0() 
{ 
        return Salary0 = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }); 
}

// ��������ȡ���ʱ�����
int *get_salary_dbase_2() { return copy(Salary2); }

// ��������ʼ���ʱ�����
int *init_salary_dbase_2()
{ 
        return Salary2 = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }); 
}

// ��������ȡĳ�չ���(Դ)
int get_contribute_0( int day ) 
{  
        if( day < 1 || day > 30 ) return 0;
        return Salary0[ (day - 1) * 2 ];
}

// ����������ĳ�չ���(Դ)
int set_contribute_0( int day, int point ) 
{  
        if( day < 1 || day > 30 ) return 0;
        return Salary0[ (day - 1) * 2 ] = point;
}

// ��������ȡĳ�չ���(Դ)
int get_salary_0( int day ) 
{  
        if( day < 1 || day > 30 ) return 0;
        return Salary0[ (day - 1) * 2 + 1 ];
}

// ����������ĳ�չ���(Դ)
int set_salary_0( int day, int point ) 
{  
        if( day < 1 || day > 30 ) return 0;
        return Salary0[ (day - 1) * 2 + 1 ] = point;
}

// ��������ȡĳ����ȡ����
int get_salary_2( int day ) 
{  
        if( day < 1 || day > 30 ) return 0;
        return Salary2[ day - 1 ];
}

// ����������ĳ����ȡ����
int set_salary_2( int day, int point ) 
{  
        if( day < 1 || day > 30 ) return 0;
        return Salary2[ day - 1 ] = point;
}

// ����������ĳ����ȡ����
int add_salary_2( int day, int point ) { return set_salary_2( day, get_salary_2(day) + point ); }

// �����������µĹ��ף�����
void insert_contribute_salary( int contribute, int salary )
{
        int i;

        for( i = 28; i >= 0; i -- )
        {
                Salary0[ i * 2 + 2 ] = Salary0[ i * 2 ];
                Salary0[ i * 2 + 3 ] = Salary0[ i * 2 + 1 ];
                Salary2[ i + 1 ] = Salary2[ i ];
        }
        Salary0[0] = contribute;  Salary0[1] = salary;  Salary2[0] = salary;
}

// -------------------------------------------------------------

// ��������ȡ���չ���
int get_contribute() { return Contribute; }

// ���������ý��չ���
int set_contribute( int point ) { return Contribute = point; }

// ���������ӽ��չ���
int add_contribute( int point ) { return set_contribute( Contribute + point ); }

// ���������ݹ��׷ֺ�(login.c ����)
void pay_salary_baseon_contribute( object who )
{
        string name;
        int day, contribute, salary, salary2, point;
	return ;
/*	
        name = this_object()->get_name();

        if( name != who->get_city_name() ) return;
        if( !( day = get_save("day") - who->get_save("salary") ) ) return;

        point = who->get_contribute();

        who->set_save( "salary", get_save("day") );    // ��ǽ���
        who->set_contribute(0);    // ��չ���

        if( day < 1 || day > 30 ) return 0;

        contribute = Salary0[ (day - 1) * 2 ];
        salary = Salary0[ (day - 1) * 2 + 1 ];
        salary2 = Salary2[ day - 1 ];

        if( salary < 1 )
        {
                write_user( who, ECHO "ǰ %d ��%s�ֺ�Ϊ %d�����ֵ� %d ��", day, name, salary, 0 );
        }
        else if( salary2 < 1 )
        {
                write_user( who, ECHO "ǰ %d ��%s�ֺ�Ϊ %d��������̫���ˣ��ֵ� %d ��", day, name, salary, 0 );
        }
        else if( contribute < 1 )
        {
                write_user( who, ECHO "ǰ %d ��%s�ֺ�Ϊ %d����û�������ף��ֵ� %d ��", day, name, salary, 0 );
        }
        else if( contribute > point )
        {
                if( salary > 10000 ) point = salary / 100 * point / contribute * 100;
                else if( point > 1000 ) point = point / 10 * salary / contribute * 10;
                else point = salary * point / contribute;

                if( point > salary2 ) point = salary2;

                who->add_cash(point);  who->add_gold_log("task", point);
                who->log_money("�ֺ�", point);
                "/sys/sys/count"->add_income("city", point);
                Salary2[ day - 1 ] -= point;

                write_user( who, ECHO "ǰ %d ��%s�ֺ�Ϊ %d�����ֵ� %d ��", day, name, salary, point );
        }
        else
        {
                who->add_cash(salary2);  who->add_gold_log("task", salary2);
                who->log_money("�ֺ�", salary2);
                "/sys/sys/count"->add_income("city", salary2);
                Salary2[ day - 1 ] = 0;

                write_user( who, ECHO "ǰ %d ��%s�ֺ�Ϊ %d�����ֵ� %d ��", day, name, salary, salary2 );
        }
*/        
}

// -------------------------------------------------------------

// ��������������
void heart_beat() { }

// ��������������(ѭ��)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 ) { __FILE__ ->heart_beat_loop_callout( this_object(), effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8 ); }

// ��������������(ѭ��)(���߸���)
void heart_beat_loop_callout( object me, int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 )    // ÿ���ִ���
{
        ITEM_EFFECT_D->into_effect(me, effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8);    // ��״����
}

// -------------------------------------------------------------

// ����������֮ǰ����
void before_destruct()
{
        object *reset;
        int i, size;

        if( arrayp( reset = this_object()->get("manager") ) )
        {
                size = sizeof(reset);
                for( i = 0; i < size; i ++ ) if( reset[i] )
                {
                        reset[i]->remove_from_scene();
                        destruct( reset[i] );
                }
        }
}
