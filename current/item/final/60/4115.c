
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 2267; }

// ���������촦��
void create()
{
        set_name("���䶷��");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(115);
        set_value(11500);
        set_max_lasting(27899);
        set("ap", 0);
        set("dp", 270);
        set("cp", 0);
        set("pp", 177);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "���䶷��";
}
