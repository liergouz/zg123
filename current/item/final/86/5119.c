
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 1444; }

// ���������촦��
void create()
{
        set_name("߱������");
        set_picid_1(8655);
        set_picid_2(8655);

        set_level(119);
        set_value(20000);
        set_max_lasting(60099);
        set("ap", 0);
        set("dp", 0);
        set("cp", 210);
        set("pp", 117);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "߱������";
}
