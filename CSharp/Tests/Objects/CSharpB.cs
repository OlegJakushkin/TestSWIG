using System;
using LibraryNamespace;

namespace Tests {
    internal class CSharpB: B {
        public override void SetA( A p ) {
            Console.WriteLine( "C# ruls." );
            base.SetA( p );
        }
    }
}