
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 2225; }

// ���������촦��
void create()
{
        set_name("Ѫɫ��װ");
        set_picid_1(6082);
        set_picid_2(6082);

        set_level(95);
        set_value(10500);
        set_max_lasting(25899);
        set("ap", 0);
        set("dp", 230);
        set("cp", 0);
        set("pp", 147);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "Ѫɫ��װ";
}
