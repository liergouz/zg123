
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2213; }

// ���������촦��
void create()
{
        set_name("����ͷ��");
        set_picid_1(6625);
        set_picid_2(6625);

        set_level(85);
        set_value(10000);
        set_max_lasting(24899);
        set("ap", 0);
        set("dp", 156);
        set("cp", 0);
        set("pp", 62);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ͷ��";
}
