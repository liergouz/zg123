
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 1454; }

// ���������촦��
void create()
{
        set_name("׷������");
        set_picid_1(8655);
        set_picid_2(8655);

        set_level(46);
        set_value(999);
        set_max_lasting(7599);
        set("ap", 62);
        set("dp", 0);
        set("cp", 98);
        set("pp", 63);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "׷������";
}
