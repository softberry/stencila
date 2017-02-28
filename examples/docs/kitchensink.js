export default `
<div id="title">Test with all nodes</div>
<p>A test Stencila document with at least one (well, that&apos;s the plan) of each node type (in alphabetical order). See additional node specific test documents in sibling folders e.g. <a href="/file://tests/document/nodes/image/index.html">image</a> </p>
<h1>Blockquote</h1>
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.</p>
<blockquote>Science is a way of thinking much more than it is a body of knowledge. <em>Carl Sagan</em></blockquote>
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.</p>
<h1>Codeblock</h1>
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.</p><pre><code class="r"># A R snippet (from the dplyr vignette)

by_tailnum &lt;- group_by(flights,=&quot;&quot; tailnum)=&quot;&quot; delay=&quot;&quot; &lt;-=&quot;&quot; summarise(by_tailnum,=&quot;&quot; count=&quot;n(),&quot; dist=&quot;mean(distance,&quot; na.rm=&quot;TRUE),&quot; filter(delay,=&quot;&quot;&gt; 20, dist &lt; 2000)

# Interestingly, the average delay is only slightly related to the
# average distance flown by a plane.
ggplot(delay, aes(dist, delay)) +
  geom_point(aes(size = count), alpha = 1/2) +
  geom_smooth() +
  scale_size_area()</code></pre>
<h1>Default</h1>
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.</p>
<ol>
    <li>First</li>
    <li>Second</li>
    <li>Third</li>
</ol>
<h1>Discussion</h1>
<div data-discussion="" id="discussion-2">
    <div data-comment="@peter at 2016-08-02T16:19:00Z">
        <p>I think the equation should actually be</p>
        <p><span data-math="asciimath">y = sqrt{x^{2sigma}}//pi</span></p>
    </div>
    <div data-comment="@mary at 2016-08-03T04:19:00Z">
        <p>No, I don&apos;t think so. I found this picture that may help you understand it&apos;s derivation better...</p><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b0/PSM_V37_D105_English_tabby_cat.jpg/320px-PSM_V37_D105_English_tabby_cat.jpg"></div>
    <div
        data-comment="@peter at 2016-08-03T04:30:00Z">
        <p>Aaaah, I see <span data-emoji="">:rolling_eyes:</span> .<em>So</em> much clearer now. When I make pi and sigma both 1, then y equals <span data-print="Math.sqrt(Math.pow(1,2*1))/3.14"></span></p>
</div>
</div>
<h1>Emoji</h1>
<p>Emoji include <span data-emoji="">:smile:</span> and <span data-emoji="">:rocket:</span> </p>
<h1>Emphasis</h1>
<h1>Heading</h1>
<h1>Image</h1>
<h1>Link</h1>
<h1>Math</h1>
<h1>Paragraph</h1>
<h1>Execute directive</h1>
<h1>Print directive</h1>
<p>Print directives evaluate an expression in the document&apos;s execution context and insert the text representation of the result in to the document. e.g. <span data-print="5*5">25</span> .</p>
<h1>Strong</h1>
<h1>Summary</h1>
<h1>Title</h1>
`