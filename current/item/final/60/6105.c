
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 2249; }

// ���������촦��
void create()
{
        set_name("��ϫ����");
        set_picid_1(6142);
        set_picid_2(6142);

        set_level(105);
        set_value(11000);
        set_max_lasting(26899);
        set("ap", 0);
        set("dp", 166);
        set("cp", 0);
        set("pp", 272);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ϫ����";
}
