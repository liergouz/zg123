
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 2280; }

// ���������촦��
void create()
{
        set_name("ӳ��Ь");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(115);
        set_value(11500);
        set_max_lasting(27899);
        set("ap", 0);
        set("dp", 53);
        set("cp", 0);
        set("pp", 0);
        set("sp", 58);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ӳ��Ь";
}
