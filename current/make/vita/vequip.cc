
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit %s;

// ��������������
int get_family() { return %d; }

// ��������Ʒ���
int get_fin_type() { return %d; }

// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%04d);
        set_picid_2(%04d);

        set_level(%d);
        set_value(%d);
        set_max_lasting(%d);
        set("ap", %d);
        set("dp", %d);
        set("cp", %d);
        set("pp", %d);
        set("sp", %d);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "%s";
}
